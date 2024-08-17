// ABDULLAH SAQIB 22I-1666 CY-C					

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	char input;      			//main input
	string var1[38][3];			//intialized 2d array
	double var2[38];			// var2 represents current price
	double var2h[38];			// var2h represents highest price
	double var2l[38];			// var2l replresents lowest prices
	double top[37],temp[37];		// top array represents array of percentage advancers where as temp array is storing top aaray
	int a1[38];				//a1 is a array that stores random 1 and 0s to increase decrease values
	double top_adv, top_dec;		//top_adv represents top advance  and to_dec represents top decliner 
	int i_adv,i_dec; 			//i denotes index i_adv represents index of top advancer where as i_dec represents index of top decliner 
	int count = 1;  			// used in tokenization
	int count1 = 1; 			// used for updating data
	int count2 = 1;
	int share[8];  				//NO. of share person adds for now its 8 but can be increased or decreased
	string share_r[8]; 			// for removing share
	int store[8]; 				// used in portfolio array finding
	//int store_i;				// for storing i 
	double gain = 0;                        // gain represents profit
	int p_bal,bal = 0,p_bal_r;	// P_bal is for previous balance where as bal is for balance, and p_bal_r is for removing balance r signifies remove
	char inputa;    		//NO. of share 
	char inputb;      		// removing share
	int store_sahres; 		// for storing no. of share used in adding and removing shares
	string name;			// stores name of buyer
	string symbol[8];		//stores sybmol of company
	string company[8];		//stores name of company
	string store_symbol;		//stores input symbol of company fro remnoval and addition of shares
	
	fstream readfile;     			// file object created
	readfile.open("companies.txt",ios::in); //file open in input mode
	int i = 0;  // both used as counters
	int j = 0;
	//cin >> input;
	srand(time(0));
	{
		for(int i = 0; i < 38 ; i++)
		{
			for(int j = 0; j < 3; j++)
			{	
				if(count == 1)
				{
					(getline(readfile,var1[i][j],','));
					count++;
				}
				else if(count == 2)
				{
					(getline(readfile,var1[i][j],','));
					count++;
				}
				else if(count == 3)
				{
					(getline(readfile,var1[i][j],'\n'));
					count = 1;
				}
				
			}			
				
		}		
	}
	double var[37];
	for(int i = 1,j = 2; i < 38 ; i++)             // converting string to double 
	{
		var[i] = stod(var1[i][2]);
		//cout<< var[i];	
		
	}
		
		
	readfile.close();
	
	do{
	
		if( count1 == 1)
		cin >> input;
	
	
		for(int i = 0 ; i < 38 ; i++)
		{ 
			a1[i] = rand()%2;           			// this loops is generating seed for increase decrease loop return 0 or 1
			//cout<<a1[i];	
		}
		for(int i = 1 ; i < 38 ; i++)
		{ 
			if(a1[i] == 1)
				var2[i] = var[i]+(var[i]*0.15);
									// this is thhe increase decrease loop var2 is the current price
			else
				var2[i] = var[i]-(var[i]*0.15);	
		}
		
	
		if (count1 == 1)                                     // these conditons are backbone of high and low
		{
			for(int i = 1 ; i < 38 ; i++)
			{ 
		
				var2h[i] = var[i];
									// storing values of var in var2h(highest)  and var2l(lowest)
				var2l[i] = var[i];
				//cout<<var2h[i];
			
			}
		}	
		for(int i = 1 ; i < 38 ; i++)
		{ 
			if(var2[i] > var2h[i])
				var2h[i] = var2[i];
									// this is for highest values and lowest values
			else if(var2[i] < var2l[i])
				var2l[i] = var2[i];
			
		}
	
		for(int i = 0 ; i < 37 ; i++)
		{                       	
			top[i] =( var2[i]/100 - var[i]/100 );
			temp[i] = top[i];					// creating copy of top in temp
			//cout<<i<<" "<<temp[i]<<endl;	
	
									// this is for top % advancer and top % decliner	
		}
		for(int i = 0 ;  i < 1 ; i++)   			// runs one time as we need 1st vlaue only 
		{
			int store;
			for(int j = i+1 ;  j < 37-i ; j++)    	// j represents net value to i and  s-i represents how many terms left by which we have to compare
			{
				if(top[i] > top[j])
				{
					store = top[i];
					top[i] = top[j];     		// bubble sorting is used and swaping is done here ;)
					top[j] = store;
					top_dec = top[0];
				}
	
			}
		
		}
	
		for(int i = 0 ;  i < 1 ; i++)   		// runs one time as we need 1st vlaue only
		{
			int store;
			for(int j = i+1 ;  j < 37-i ; j++)    // j represents net value to i and  s-i represents how many terms left by which we have to compare
			{
				if(top[i] < top[j])
				{
					store = top[i];
					top[i] = top[j];     // bubble sorting is used and swaping is done here ;)
					top[j] = store;
					top_adv = top[0];
				}
	
			}
		
		}
		for(int i = 0 ; i < 37 ; i++)
		{
			if(top_adv == temp[i])
			{
				i_adv = i;
				break;
			}
	
	
	
		}
		for(int i = 0 ; i < 37 ; i++)
		{
			if(top_dec == temp[i])
			{
				i_dec = i;
				break;
			}
	
	
	
		}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	cout<<"\033[1;33m"<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<"\033[0;0m"<<endl;
	cout<<"\033[1;33m"<<"|"<<setw(30)<<setfill(' ')<<" "<<"Show updates: u  Exit: e  Add\\Remove no. of Stock: A  Add Stock: a  Add\\Withdraw money to account: m"  <<setw(29)<<setfill(' ')<<"|"<<"\033[0;0m"<<endl;	
	for(int i = 0; i < 38 ; i++)
	{	
		cout<<setw(160)<<setfill('-')<<"-";
		cout<<setfill(' ')<<endl;
		for(int j = 0; j < 3; j++)
		{	
			if(count == 1)
			{
				if( i == 0)
				cout<<"\033[1;33m";
				cout<<"|"<<left<<setw(30)<<var1[i][j]<<"|";    //symbol
				count++;
			}
			else if(count == 2)
			{
				cout<<setw(60)<<var1[i][j]<<"|";         	//company name
				count++;
			}
			else if(count == 3)
			{
				if(i==0)
					cout<<right<<setw(14)<<"\033[1;33m"<<"Previous Price"<<"|"<<"\033[0;0m";		//previous price
				else
					cout<<right<<setw(21)<<var[i]<<"|";
				count = 1;
				
				
				if(var[i] < var2[i])
				{	
					if(i == 0)
					{
						cout<<setw(12)<<"\033[1;33m"<<"current price"<<"|"<<"\033[0;0m";     // current price / highest / lowest
						cout<<setw(12)<<"Highest"<<"|";
						cout<<setw(12)<<"Lowest"<<"|";
					}
					else 
					{
						cout<<"\033[0;32m"<<right<<setw(17)<<var2[i]<<"\u2191"<<"\033[0;0m"<<"|";
						cout<<right<<setw(12)<<var2h[i]<<"|";
						cout<<right<<setw(12)<<var2l[i]<<"|";
					}	
				}
				else
				{	
					if(i == 0)
					{
						cout<<setw(12)<<"\033[1;33m"<<"current price"<<"|"<<"\033[0;0m";
						cout<<setw(12)<<"\033[1;33m"<<"Highest"<<"|"<<"\033[0;0m";
						cout<<setw(13)<<"\033[1;33m"<<"Lowest"<<"|"<<"\033[0;0m";
					}
					else
					{
						cout<<"\033[0;31m"<<right<<setw(17)<<var2[i]<<"\u2193"<<"\033[0;0m"<<"|";
						cout<<right<<setw(12)<<var2h[i]<<"|";
						cout<<right<<setw(12)<<var2l[i]<<"|";
					}		
				}
				
				
				
			}			
			
		}
	cout<<endl;		
	
	
	}
	
	cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;
	cout<<"|"<<"\033[1;32m"<<"Top % advancer"<<"\033[0;0m"<<setw(17)<<"|"<<"\033[1;32m"<<setw(17)<<left<<var1[i_adv][0]<<right<<"\033[0;0m"<<setw(44)<<"|"<<setw(67)<<"|"<<endl;
	cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;
	cout<<"|"<<"\033[1;31m"<<"Top % decliner"<<"\033[0;0m"<<setw(17)<<"|"<<"\033[1;32m"<<setw(17)<<left<<var1[i_dec][0]<<right<<"\033[0;0m"<<setw(44)<<"|"<<setw(67)<<"|"<<endl;
	cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;
	cin>> input;
		
		//cout<<right<<setw(12)<<"Top % advancer"<<"|"<<top_adv<<endl;
		//cout<<right<<setw(12)<<"Top % decliner"<<"|"<<top_dec<<endl;
		//cout<<right<<setw(12)<<"index Top % advancer"<<"|"<<i_adv<<endl;
		//cout<<right<<setw(12)<<"index % decliner"<<"|"<<i_dec<<endl;
/*	if(input == 'r')
	{
		cout<<"Enter Symbol: ";
		do
			{	
				
				cin>>share_r[j];
				cin >> inputb;
					
			for(int i = 0 ; i < j ; i++)
			{
				if(symbol[i] == share_r[j])
				{
					symbol[i] == symbol[i+8];
					company[i] == company[i+8];
					share[i] == share[i+8];
					}
			}	
			
			j++;	
			}while(inputb != 'c');
			
	
	readfile.open("portfolio.txt",ios::out); 				//file open
			readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
			readfile<<"Portfolio owner: "<<name<<endl;

			readfile<<left<<setw(12)<<setfill(' ')<<"Stocks"<<right<<setw(40)<<setfill(' ')<<"Company Name"<<setw(12)<<setfill(' ')<<"shares"<<setw(12)<<setfill(' ')<<"Close"<<setw(12)<<setfill(' ')<<"Previous"<<setw(12)<<setfill(' ')<<"Gain/Loss"<<setw(12)<<setfill(' ')<<"High"<<setw(12)<<setfill(' ')<<"Low"<<endl;
			readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl<<endl;
			for(int k = 0 ; k < i; k++)
			{
				readfile<<left<<setw(12)<<setfill(' ')<<symbol[k]<<right<<setw(40)<<setfill(' ')<<company[k]<<setw(12)<<setfill(' ')<<share[k]<<setw(12)<<setfill(' ')<<var2[store[k]]<<setw(12)<<setfill(' ')<<var[store[k]]<<setw(12)<<setfill(' ')<<share[k]*(var2[store[k]]-var[store[k]])<<setw(12)<<setfill(' ')<<var2h[store[k]]<<setw(12)<<setfill(' ')<<var2l[store[k]]<<endl;
	
	
				gain += share[k]*(var2[store[k]]-var[store[k]]);
				bal += (share[k] * var[store[k]]);
				}
			bal =  p_bal-bal;
			//bal = p_bal-bal;
			readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
			readfile<<left<<setw(47)<<setfill(' ')<<"Today’s Gain or Loss (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<gain<<setw(15)<<setfill(' ')<<"*"<<endl;
			readfile<<left<<setw(45)<<setfill(' ')<<"Previous Balance (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<p_bal<<setw(15)<<setfill(' ')<<"*"<<endl;
			readfile<<left<<setw(45)<<setfill(' ')<<"New Balance (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<bal<<setw(15)<<setfill(' ')<<"*"<<endl;
			readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
	
			readfile.close(); 						
	}*/	
		
		
		
		
	
	if(input == 'm')
	{
		int choice = 0;
		
		cout<<"For adding Money press 1: "<<endl;
		cout<<"For removing Money press 2: "<<endl;
		cin>>choice;
		switch(choice)
		{	case 1:
			cout<<"Add Balance: ";
			cin>>p_bal;
			cin.ignore();
			break;
			
			case 2:
			cout<<"Remove Balance: ";
			cin>>p_bal_r;
			p_bal -=  p_bal_r;
			cin.ignore();
			break;
			
		}
		
		readfile.open("portfolio.txt",ios::out); 				//file open
		readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
		readfile<<"Portfolio owner: "<<name<<endl;

		readfile<<left<<setw(12)<<setfill(' ')<<"Stocks"<<right<<setw(40)<<setfill(' ')<<"Company Name"<<setw(12)<<setfill(' ')<<"shares"<<setw(12)<<setfill(' ')<<"Close"<<setw(12)<<setfill(' ')<<"Previous"<<setw(12)<<setfill(' ')<<"Gain/Loss"<<setw(12)<<setfill(' ')<<"High"<<setw(12)<<setfill(' ')<<"Low"<<endl;
		readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl<<endl;
		for(int k = 0 ; k < i; k++)
			{
				readfile<<left<<setw(12)<<setfill(' ')<<symbol[k]<<right<<setw(40)<<setfill(' ')<<company[k]<<setw(12)<<setfill(' ')<<share[k]<<setw(12)<<setfill(' ')<<var2[store[k]]<<setw(12)<<setfill(' ')<<var[store[k]]<<setw(12)<<setfill(' ')<<(var2[store[k]]-var[store[k]])<<setw(12)<<setfill(' ')<<var2h[store[k]]<<setw(12)<<setfill(' ')<<var2l[store[k]]<<endl;
	
	
				gain = share[k] * (var2[store[k]]-var[store[k]]);
				bal += (share[k] * var[store[k]]);
			}
		bal =  p_bal-bal;
		//gain = share[k] * (var2[store[k]]-var[store[k]]);
		readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
		readfile<<left<<setw(47)<<setfill(' ')<<"Today’s Gain or Loss (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<gain<<setw(15)<<setfill(' ')<<"*"<<endl;
		readfile<<left<<setw(45)<<setfill(' ')<<"Previous Balance (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<p_bal<<setw(15)<<setfill(' ')<<"*"<<endl;
		readfile<<left<<setw(45)<<setfill(' ')<<"New Balance (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<bal<<setw(15)<<setfill(' ')<<"*"<<endl;
		readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
	
		readfile.close(); 
		cin >> input;
			
		
		
	}
	if(input == 'A')
	{	
		int choice = 0;
		cout<<"Enter Symbol of share: ";
		cin >> store_symbol;
		for(int i = 0; i < 37; i++)
		{
			if(symbol[i] == store_symbol)
			{
				cout<<"For adding Shares press 1: "<<endl;
				cout<<"For removing Shares press 2: "<<endl;
				cin>>choice;
				switch(choice)
				{
					case 1:
					cout<<"Add shares: ";
					cin >> store_sahres;
					share[i] += store_sahres;
					break;
					case 2:
					cout<<"Remove shares: ";
					cin >> store_sahres;
					share[i] -= store_sahres;
					break;
					
				}
		
			}
		}
		
		readfile.open("portfolio.txt",ios::out); 				//file open
		readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
		readfile<<"Portfolio owner: "<<name<<endl;

		readfile<<left<<setw(12)<<setfill(' ')<<"Stocks"<<right<<setw(40)<<setfill(' ')<<"Company Name"<<setw(12)<<setfill(' ')<<"shares"<<setw(12)<<setfill(' ')<<"Close"<<setw(12)<<setfill(' ')<<"Previous"<<setw(12)<<setfill(' ')<<"Gain/Loss"<<setw(12)<<setfill(' ')<<"High"<<setw(12)<<setfill(' ')<<"Low"<<endl;
		readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl<<endl;
		for(int k = 0 ; k < i; k++)
		{
			readfile<<left<<setw(12)<<setfill(' ')<<symbol[k]<<right<<setw(40)<<setfill(' ')<<company[k]<<setw(12)<<setfill(' ')<<share[k]<<setw(12)<<setfill(' ')<<var2[store[k]]<<setw(12)<<setfill(' ')<<var[store[k]]<<setw(12)<<setfill(' ')<<(var2[store[k]]-var[store[k]])<<setw(12)<<setfill(' ')<<var2h[store[k]]<<setw(12)<<setfill(' ')<<var2l[store[k]]<<endl;
	
	
			gain = share[k]*(var2[store[k]]-var[store[k]]);
			bal += (share[k] * var[store[k]]);
		}
		bal =  p_bal-bal;
		//gain = (var2[store[k]]-var[store[k]]);
		readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
		readfile<<left<<setw(47)<<setfill(' ')<<"Today’s Gain or Loss (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<gain<<setw(15)<<setfill(' ')<<"*"<<endl;
		readfile<<left<<setw(45)<<setfill(' ')<<"Previous Balance (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<p_bal<<setw(15)<<setfill(' ')<<"*"<<endl;
		readfile<<left<<setw(45)<<setfill(' ')<<"New Balance (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<bal<<setw(15)<<setfill(' ')<<"*"<<endl;
		readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
	
		readfile.close(); 
		cin >> input; 
	}	
	//if(count2 == 1) 
	if(input == 'a')
	{
		//cout<<"I am IN"<<endl;
		cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;
		//if(count2 == 1)
		{
			cout<<"Name: ";
			cin.ignore();
			getline(cin,name);
			
			
			
		//cout<<setw(72)<<setfill(' ')<<"\033[1;33m"<<"Portfolio owner: "<<name<<"\033[0;0m"<<setw(60)<<endl;
		
			
			do
			{	
				cout<<"Symbol of shares: ";
				cin>>symbol[i];
				cout<<"Company: ";
				cin.ignore();
				getline(cin,company[i]);
				cout<<"Number of shares: ";
				cin>>share[i];
				
				cin >> inputa;
				
				for(int j = 0; j <8 ;j++)                                           // finding array in stock market to get further data
				{
					for(int i = 0 ; i < 38 ; i++)
					{
						if(symbol[j] == var1[i][0])
						{
							//cout<<"Hello I Got it";
							//cout<<i<<endl;
							store[j] = i;
							
						}
						
					}
					
				}
			
			i++;	
			}while(inputa != 'c');		
			readfile.open("portfolio.txt",ios::out); 				//file open
			readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
			readfile<<"Portfolio owner: "<<name<<endl;

			readfile<<left<<setw(12)<<setfill(' ')<<"Stocks"<<right<<setw(40)<<setfill(' ')<<"Company Name"<<setw(12)<<setfill(' ')<<"shares"<<setw(12)<<setfill(' ')<<"Close"<<setw(12)<<setfill(' ')<<"Previous"<<setw(12)<<setfill(' ')<<"Gain/Loss"<<setw(12)<<setfill(' ')<<"High"<<setw(12)<<setfill(' ')<<"Low"<<endl;
			readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl<<endl;
			for(int k = 0 ; k < i; k++)
			{
				readfile<<left<<setw(12)<<setfill(' ')<<symbol[k]<<right<<setw(40)<<setfill(' ')<<company[k]<<setw(12)<<setfill(' ')<<share[k]<<setw(12)<<setfill(' ')<<var2[store[k]]<<setw(12)<<setfill(' ')<<var[store[k]]<<setw(12)<<setfill(' ')<<(var2[store[k]]-var[store[k]])<<setw(12)<<setfill(' ')<<var2h[store[k]]<<setw(12)<<setfill(' ')<<var2l[store[k]]<<endl;
	
	
				gain = share[k]*(var2[store[k]]-var[store[k]]);
				bal += (share[k] * var[store[k]]);
				}
			bal =  p_bal-bal;
			//bal = p_bal-bal;
			readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
			readfile<<left<<setw(47)<<setfill(' ')<<"Today’s Gain or Loss (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<gain<<setw(15)<<setfill(' ')<<"*"<<endl;
			readfile<<left<<setw(45)<<setfill(' ')<<"Previous Balance (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<p_bal<<setw(15)<<setfill(' ')<<"*"<<endl;
			readfile<<left<<setw(45)<<setfill(' ')<<"New Balance (Rs.)"<<setw(15)<<setfill(' ')<<"*"<<right<<setw(15)<<setfill(' ')<<bal<<setw(15)<<setfill(' ')<<"*"<<endl;
			readfile<<setw(124)<<setfill('*')<<"*"<<setfill(' ')<<endl;
	
			readfile.close(); 							// file closed 
			
			/*
			cout<<"\033[1;33m"<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<"\033[0;0m"<<endl;
			cout<<setw(72)<<setfill(' ')<<"\033[1;33m"<<"Portfolio owner: "<<name<<"\033[0;0m"<<endl;
			cout<<"\033[1;33m"<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<"\033[0;0m"<<endl;
			cout<<"\033[1;33m"<<"|"<<setw(30)<<setfill(' ')<<" "<<"Show updates: ⏎ Live Market: L Add Stock: A Remove Stock: R Add money to account: M Withdraw money: W"<<setw(28)<<setfill(' ')<<"|"<<"\033[0;0m"<<endl;
			cout<<"\033[1;33m"<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<"\033[0;0m"<<endl;
		
		
		
			cout<<left<<setw(25)<<setfill(' ')<<"|Stocks"<<right<<"|"<<setw(18)<<setfill(' ')<<"Company Name"<<"|"<<setw(18)<<setfill(' ')<<"shares"<<"|"<<setw(18)<<setfill(' ')<<"Close"<<"|"<<setw(18)<<setfill(' ')<<"Previous"<<"|"<<setw(18)<<setfill(' ')<<"Gain/Loss"<<"|"<<setw(18)<<setfill(' ')<<"High"<<"|"<<setw(19)<<setfill(' ')<<"Low"<<"|"<<endl;
	cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;
	
			for(int k = 0 ; k < i; k++)
			{
				if((share[k]*(var2[store[k]]-var[store[k]])) > 0)
				{
					cout<<"|"<<left<<setw(23)<<setfill(' ')<<symbol[k]<<" "<<right<<"|"<<setw(18)<<setfill(' ')<<company[k]<<"|"<<setw(18)<<setfill(' ')<<share[k]<<"|"<<setw(18)<<setfill(' ')<<var2[store[k]]<<"|"<<setw(18)<<setfill(' ')<<var[store[k]]<<"|"<<"\033[0;32m"<<setw(18)<<setfill(' ')<<share[k]*(var2[store[k]]-var[store[k]])<<"\033[0;0m"<<"|"<<setw(18)<<setfill(' ')<<var2h[store[k]]<<"|"<<setw(19)<<setfill(' ')<<var2l[store[k]]<<"|"<<endl;
	
				}
				else 
				{
					cout<<"|"<<left<<setw(23)<<setfill(' ')<<symbol[k]<<" "<<right<<"|"<<setw(18)<<setfill(' ')<<company[k]<<"|"<<setw(18)<<setfill(' ')<<share[k]<<"|"<<setw(18)<<setfill(' ')<<var2[store[k]]<<"|"<<setw(18)<<setfill(' ')<<var[store[k]]<<"|"<<"\033[0;31m"<<setw(18)<<setfill(' ')<<share[k]*(var2[store[k]]-var[store[k]])<<"\033[0;0m"<<"|"<<setw(18)<<setfill(' ')<<var2h[store[k]]<<"|"<<setw(19)<<setfill(' ')<<var2l[store[k]]<<"|"<<endl;
	
				}

			}
		
	cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;
	if (gain > 0)
	cout<<left<<setw(47)<<setfill(' ')<<"|Today’s Gain or Loss (Rs.)"<<setw(15)<<setfill(' ')<<"|"<<"\033[0;32m"<<right<<setw(15)<<setfill(' ')<<gain<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
	else
	cout<<left<<setw(47)<<setfill(' ')<<"|Today’s Gain or Loss (Rs.)"<<setw(15)<<setfill(' ')<<"|"<<"\033[0;31m"<<right<<setw(15)<<setfill(' ')<<gain<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
	if (p_bal > 0)
	cout<<left<<setw(45)<<setfill(' ')<<"|Previous Balance (Rs.)"<<setw(15)<<setfill(' ')<<"|"<<"\033[0;32m"<<right<<setw(15)<<setfill(' ')<<p_bal<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
	else
	cout<<left<<setw(45)<<setfill(' ')<<"|Previous Balance (Rs.)"<<setw(15)<<setfill(' ')<<"|"<<"\033[0;31m"<<right<<setw(15)<<setfill(' ')<<p_bal<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
	if( bal+gain > 0 )
	cout<<left<<setw(45)<<setfill(' ')<<"|New Balance (Rs.)"<<setw(22)<<setfill(' ')<<"|""\033[0;32m"<<right<<setw(15)<<setfill(' ')<<p_bal+gain<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
	else
	cout<<left<<setw(45)<<setfill(' ')<<"|New Balance (Rs.)"<<setw(22)<<setfill(' ')<<"|""\033[0;31m"<<right<<setw(15)<<setfill(' ')<<p_bal+gain<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
	cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;*/
		
			
	cin >> input;
	

		}
		}
	
	count2++;
	if(input == 'p')
		{
			cout<<"\033[1;33m"<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<"\033[0;0m"<<endl;
			cout<<setw(72)<<setfill(' ')<<"\033[1;33m"<<"Portfolio owner: "<<name<<"\033[0;0m"<<endl;
			cout<<"\033[1;33m"<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<"\033[0;0m"<<endl;
			cout<<"\033[1;33m"<<"|"<<setw(30)<<setfill(' ')<<" "<<"Show updates: u  Exit: e  Add\\Remove no. of Stock: A  Add Stock: a  Add\\Withdraw money to account: m"  <<setw(29)<<setfill(' ')<<"|"<<"\033[0;0m"<<endl;
			cout<<"\033[1;33m"<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<"\033[0;0m"<<endl;
		
		
		
			cout<<left<<setw(25)<<setfill(' ')<<"|Stocks"<<right<<"|"<<setw(18)<<setfill(' ')<<"Company Name"<<"|"<<setw(18)<<setfill(' ')<<"shares"<<"|"<<setw(18)<<setfill(' ')<<"Close"<<"|"<<setw(18)<<setfill(' ')<<"Previous"<<"|"<<setw(18)<<setfill(' ')<<"Gain/Loss"<<"|"<<setw(18)<<setfill(' ')<<"High"<<"|"<<setw(19)<<setfill(' ')<<"Low"<<"|"<<endl;
	cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;
	
			for(int k = 0 ; k < i; k++)
			{
				if(gain > 0)
				{
					cout<<"|"<<left<<setw(23)<<setfill(' ')<<symbol[k]<<" "<<right<<"|"<<setw(18)<<setfill(' ')<<company[k]<<"|"<<setw(18)<<setfill(' ')<<share[k]<<"|"<<setw(18)<<setfill(' ')<<var2[store[k]]<<"|"<<setw(18)<<setfill(' ')<<var[store[k]]<<"|"<<"\033[0;32m"<<setw(18)<<setfill(' ')<<(var2[store[k]]-var[store[k]])<<"\033[0;0m"<<"|"<<setw(18)<<setfill(' ')<<var2h[store[k]]<<"|"<<setw(19)<<setfill(' ')<<var2l[store[k]]<<"|"<<endl;
	
				}
				else 
				{
					cout<<"|"<<left<<setw(23)<<setfill(' ')<<symbol[k]<<" "<<right<<"|"<<setw(18)<<setfill(' ')<<company[k]<<"|"<<setw(18)<<setfill(' ')<<share[k]<<"|"<<setw(18)<<setfill(' ')<<var2[store[k]]<<"|"<<setw(18)<<setfill(' ')<<var[store[k]]<<"|"<<"\033[0;31m"<<setw(18)<<setfill(' ')<<(var2[store[k]]-var[store[k]])<<"\033[0;0m"<<"|"<<setw(18)<<setfill(' ')<<var2h[store[k]]<<"|"<<setw(19)<<setfill(' ')<<var2l[store[k]]<<"|"<<endl;
	
				}

			}
		
		cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;
		if (gain > 0)
		cout<<left<<setw(47)<<setfill(' ')<<"|Today’s Gain or Loss (Rs.)"<<setw(15)<<setfill(' ')<<"|"<<"\033[0;32m"<<right<<setw(15)<<setfill(' ')<<gain<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
		else
		cout<<left<<setw(47)<<setfill(' ')<<"|Today’s Gain or Loss (Rs.)"<<setw(15)<<setfill(' ')<<"|"<<"\033[0;31m"<<right<<setw(15)<<setfill(' ')<<gain<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
		if (p_bal > 0)
		cout<<left<<setw(45)<<setfill(' ')<<"|Previous Balance (Rs.)"<<setw(15)<<setfill(' ')<<"|"<<"\033[0;32m"<<right<<setw(15)<<setfill(' ')<<p_bal<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
		else
		cout<<left<<setw(45)<<setfill(' ')<<"|Previous Balance (Rs.)"<<setw(15)<<setfill(' ')<<"|"<<"\033[0;31m"<<right<<setw(15)<<setfill(' ')<<p_bal<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
		if( bal > 0 )
		cout<<left<<setw(45)<<setfill(' ')<<"|New Balance (Rs.)"<<setw(22)<<setfill(' ')<<"|""\033[0;32m"<<right<<setw(15)<<setfill(' ')<<bal<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
		else
		cout<<left<<setw(45)<<setfill(' ')<<"|New Balance (Rs.)"<<setw(22)<<setfill(' ')<<"|""\033[0;31m"<<right<<setw(15)<<setfill(' ')<<bal<<setw(15)<<setfill(' ')<<"\033[0;0m"<<"|"<<setw(75)<<setfill(' ')<<"|"<<endl;
		cout<<setw(160)<<setfill('-')<<"-"<<setfill(' ')<<endl;
		
		
		cin >> input;
		
	}
		
	count1++;
		
		
	//cin >> input;
		
		
		
		
		
		if (count1 != 1)
		for(int i = 1 ; i < 38 ; i++)
		{ 
			var[i] = var2[i];
								//updating for next run	
		}
	
	
	}while(input != 'e');


	
return 0;
}
