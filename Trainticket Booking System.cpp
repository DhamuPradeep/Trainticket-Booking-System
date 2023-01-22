#include<bits/stdc++.h>
using namespace std;

class TrainTicket{
	
	private:
	vector<vector<long long> > coach;
	int choice,availableseats,passno;
	string name,berthpref,gender,age;
	long long pnr;
	map<long long,string>mp;
	map<long long,int>row,col;
	
	public: 	
		void options();
		void createcoach();
		void available();
		void bookTicket();
		void cancel();
		void printChart();
};

void TrainTicket::options(){
	while(1){
		cout << "1.Create the coach\n";
		cout << "2.Check the availability\n";
		cout << "3.Book the ticket\n";
		cout << "4.Cancel the ticket\n";
		cout << "5.Print the chart\n";
		cout << "6.Exit\n\n";
		cout << "Enter the Choice: ";
		cin >> choice;
		cout << "\n\n";
		if(choice == 1) createcoach();
		else if(choice == 2) available();
		else if(choice == 3) bookTicket();
		else if(choice == 4) cancel();
		else if(choice == 5) printChart();
		else{
			cout << "------------------------\n";
			cout << "|  Application Closed  |\n";
			cout << "------------------------\n\n";
			break;
		}
	}
}

void TrainTicket::createcoach(){
	coach.resize(18,vector<long long>(5,-1));
	availableseats = 18*5;
	passno = 1;
	cout << "-------------------------------\n";
	cout << "|  Caoch Created Successfully  |\n";
	cout << "--------------------------------\n\n";
}

void TrainTicket::available(){
	cout << "Available Seats : " << availableseats << "\n\n";
	for(int i = 0;i<18;i++){
		for(int j = 0;j<5;j++){
			if(coach[i][j] == -1) cout << "# "; 
			else cout << coach[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void TrainTicket::bookTicket(){
	if(availableseats == 0){
		cout << "Sorry!! All the seats are filled\n\n";
		return;
	}
	cout << "Enter the Name : ";
	cin >> name;
	cout << "Enter the Age : ";
	cin >> age;
	cout << "Enter the Gender(Male/Female): ";
	cin >> gender;
	cout << "Enter the Berth Preference(L/M/U/SU/SL) : ";
	cin >> berthpref;
	cout << "Enter the PNR number : ";
	cin >> pnr;
	if(mp.find(pnr) != mp.end()){
		cout << "\nEntered PNR number is already registered\n";
		cout << "Please enter a valid PNR number\n\n";
		return;
	}
	if(berthpref == "L"){
		for(int i = 0;i<18;i++){
			if(coach[i][0] == -1){
				coach[i][0] = passno;
				availableseats--;
				row[pnr] = i;
				col[pnr] = 0;
				break;
			}  
		}
	}else if(berthpref == "M"){
		for(int i = 0;i<18;i++){
			if(coach[i][1] == -1){
				coach[i][1] = passno;
				availableseats--;
				row[pnr] = i;
				col[pnr] = 1;
				break;
			}
		}
	}else if(berthpref == "U"){
		for(int i = 0;i<18;i++){
			if(coach[i][2] == -1){
				coach[i][2] = passno;
				availableseats--;
				row[pnr] = i;
				col[pnr] = 2;
				break;
			}
		}
	}else if(berthpref == "SU"){
		for(int i = 0;i<18;i++){
			if(coach[i][3] == -1){
				coach[i][3] = passno;
				availableseats--;
				row[pnr] = i;
				col[pnr] = 3;
				break;
			}
		}
	}else if(berthpref == "SL"){
		for(int i = 0;i<18;i++){
			if(coach[i][4] == -1){
				coach[i][3] = passno;
				availableseats--;
				row[pnr] = i;
				col[pnr] = 4;
				break;
			}
		}
	}
	passno++;
	mp[pnr] = name + " " + age + " " + gender;
	cout << "---------------------------------------------------\n";
	cout << "| Your Seat Booked Successfully. Happy Journey !! |\n";
	cout << "---------------------------------------------------\n\n"; 
}


void TrainTicket::cancel(){
	cout << "Enter the PNR number : ";
	cin >> pnr;
	if(mp.find(pnr) == mp.end()){
		cout << "\nPlease enter a valid PNR number\n\n";
		return;
	}
	coach[row[pnr]][col[pnr]] = -1;
	row.erase(pnr);
	col.erase(pnr);
	mp.erase(pnr);
	cout << "-------------------------------------\n";
	cout << "| Your ticket canceled successfully |\n";
	cout << "-------------------------------------\n\n";
}

void TrainTicket::printChart(){
	cout << "Chart Prepared\n\n";
	cout << "Name          PNR          Age          Gender\n";
	map<long long,string>::iterator x = mp.begin();
	for(;x!=mp.end();x++){
		string name1,age1,gen1;
		int i;
		for(i = 0;x->second[i] != ' ';i++) name1+=x->second[i];
		i++;
		for(;x->second[i]!=' ';i++) age1+=x->second[i];
		i++;
		for(;i<x->second.size();i++) gen1+=x->second[i];
		cout << name1 << "     " << x->first << "     " << age1 << "     " << gen1 << "\n";
	}
	cout << "\n";
}
int main(){
	
	TrainTicket train;
	train.options();
	
	return 0;
}
