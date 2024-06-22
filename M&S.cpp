#include <iostream>
#include<stdlib.h>
#include <queue>
#include<cmath>
#include <iomanip>
using namespace std;

int no_customers = 10;
float mean_service;
float mean_service2;
float mean_custmoers;

double service_time_at_serverr;
double service_time_at_serverr1;
double service_time_at_serverr2;
double rand_no_of_inter_arrival_time;
double randome_numbers_of_server_service_time;
double randome_numbers_of_server_service_time1;
double randome_numbers_of_server_service_time2;

char choose_law_customer;
char choose_law_server;
char choose_law_server2;
float a1, a2, a3, b1, b2, b3;

double exp_avg_delay = 0;
double q_length = 0;
double uti_server = 0;
double uti_server2 = 0;

double tn = 0;


int number_interival_1 = 0;
int number_interival_2 = 0;
int number_interival_3 = 0;


double cumulative_1 = 0;
double cumulative_2 = 0;
double cumulative_3 = 0;


double* Time_between_process = new double[number_interival_1];
double* Time_between_process2 = new double[number_interival_2];
double* Time_between_process3 = new double[number_interival_3];




double* probability_1 = new double[number_interival_1];
double* probability_2 = new double[number_interival_2];
double* probability_3 = new double[number_interival_3];




double* cumulative_array = new double[number_interival_1];
double* cumulative_array2 = new double[number_interival_2];
double* cumulative_array3 = new double[number_interival_3];




double* num_ass_1_start = new double[number_interival_1];
double* num_ass_1_start2 = new double[number_interival_2];
double* num_ass_1_start3 = new double[number_interival_3];




double* num_ass_1_end = new double[number_interival_1];
double* num_ass_1_end2 = new double[number_interival_2];
double* num_ass_1_end3 = new double[number_interival_3];




//--------------------------
double* rand_no_of_IAT = new double[no_customers]; //RANDOME NUMBER OF INTER ARRIVAL TIME

double* rand_no_of_SST = new double[no_customers]; // RANDOME NUMBER OF SERVICE SERVER TIME
double* rand_no_of_SST2 = new double[no_customers]; // RANDOME NUMBER OF SERVICE SERVER TIME

double* IAT = new double[no_customers]; //INTER ARRVAL TIME
double* Arival_T = new double[no_customers]; //ARRVAL TIME

double* STAtS = new double[no_customers]; //Server time at server
double* STAtS2 = new double[no_customers]; //Server time at server

double* Time_SB = new double[no_customers]; //time server begin
double* Time_SB2 = new double[no_customers]; //time server begin

double* Time_SE = new double[no_customers]; //time server END
double* Time_SE2 = new double[no_customers]; //time server END

double Time_SE_temp = 0;
double Time_SE2_temp = 0;

double* Customer_D = new double[no_customers]; //Customer Delay
double* Customer_D2 = new double[no_customers]; //Customer Delay
double* Customer_D_T = new double[no_customers]; //Customer Delay
double Sum_Delay = 0;

double result = 0;

double* Idle = new double[no_customers]; //Idle
double* Idle2 = new double[no_customers]; //Idle
double Sum_idle = 0;
double Sum_idle2 = 0;





void Print_output(double output) {
	cout << setw(17) << left << setprecision(3) << output;

}

double exponential_law(double mean, double rendome_number) {

	result = ((mean * -1) * log(rendome_number));
	return result;

}
double uniForm_law(float a, float b, double rendome_number) {

	result = (a + (b - a) * (rendome_number));

	return result;

}

double emparical_law(double rand) {

	for (int g = 1; g <= number_interival_1; g++)
	{
		if (rand >= num_ass_1_start[g] && rand <= num_ass_1_end[g]) {
			result = Time_between_process[g];
			break;
		}

	}


	return result;
}

double emparical_law_serv(double rand) {

	for (int g = 1; g <= number_interival_2; g++)
	{
		if (rand >= num_ass_1_start2[g] && rand <= num_ass_1_end2[g]) {
			result = Time_between_process2[g];
			break;
		}

	}


	return result;

}

double emparical_law_serv2(double rand) {

	for (int g = 1; g <= number_interival_3; g++)
	{
		if (rand >= num_ass_1_start3[g] && rand <= num_ass_1_end3[g]) {
			result = Time_between_process3[g];
			break;
		}

	}


	return result;

}

void single_server() {


	cout << "Enter Number of customer \n";
	cin >> no_customers;

	cout << "-----------------------------------\n";
	//----------------------------- 
	for (int x = 1; x <= no_customers; x++)
	{
		cout << "Enter Random Num inter_arrival_time  " << x << endl;
		cin >> rand_no_of_IAT[x];
	}
	//----------------------------- 

	cout << "-----------------------------------\n";

	//----------------------------- 

	for (int x = 1; x <= no_customers; x++)
	{
		cout << "Enter  Random Num server_service_time  " << x << endl;
		cin >> rand_no_of_SST[x];


	}
	cout << "-----------------------------------\n";

	//----------------------------- 

	cout << "Select Law You Want To To Calculate Inter Arr Time......\n";
	cout << "1- exponential Law\n";
	cout << "2- uniForm Law\n";
	cout << "3- EmparicaL Law\n";
	cin >> choose_law_customer;
	switch (choose_law_customer) {
	case'1':
		//Ask for the mean for the randome numbers of inter arrival time

		cout << "Enter Mean Random Num inter_arrival_time \n";

		cin >> mean_custmoers;

		cout << "-----------------------------------\n";

		IAT[1] = (exponential_law(mean_custmoers, rand_no_of_IAT[1]));

		break;
	case'2':
		//Ask for the mean for the random numbers of inter arrival time

		cout << "Enter first inter-arrival-time period: \nfrom:";

		cin >> a1;

		//	//Ask for the mean for the random numbers of server service time

		cout << "Enter second inter-arrival-time period: \n";

		cin >> b1;

		IAT[1] = (uniForm_law(a1, b1, rand_no_of_IAT[1]));
		break;
	case'3':
		//To enter number of rows
		cout << "Enter_Num_arrival_interival\n";
		cin >> number_interival_1;
		for (int i = 1; i <= number_interival_1; i++) {
			cout << "Enter_Num_between_process: " << i << ':' << "and" << i + 1 << '\n';
			cin >> Time_between_process[i];
		}
		//To_get_probability
		for (int i = 1; i <= number_interival_1; i++)
		{
			cout << "enter number of probability: " << i << ':' << "and" << i + 1 << '\n';
			cin >> probability_1[i];
			cumulative_1 += probability_1[i];
			cumulative_array[i] = cumulative_1;
		}


		//to get numbers of start and end
		num_ass_1_start[1] = 0.01;
		num_ass_1_end[1] = cumulative_array[1];
		for (int i = 2; i <= number_interival_1; i++)
		{
			num_ass_1_end[i] = cumulative_array[i];
			num_ass_1_start[i] = (num_ass_1_end[i - 1] + 0.01);
			if (num_ass_1_end[i] == 1) {
				num_ass_1_end[i] = 0.00;
			}

		}



		IAT[1] = emparical_law(rand_no_of_IAT[1]);

		break;
	default:
		cout << "3nd 3m fat7y\n";
	}

	//----------------------------- 
	double arrival_time = 0;
	double server_end = 0;
	//----------------------------- 

	cout << "Select Law You Want To Use To Calculate Service Time At Serverr......\n";
	cout << "1- exponential Law\n";
	cout << "2- uniForm Law\n";
	cout << "3- EmparicaL Law\n";
	cin >> choose_law_server;
	switch (choose_law_server) {
	case'1':

		//	//Ask for the mean for the randome numbers of server service time

		cout << "Enter Mean Random Num Server Service Time \n";

		cin >> mean_service;

		cout << "-----------------------------------\n";

		STAtS[1] = exponential_law(mean_service, rand_no_of_SST[1]);

		break;
	case'2':
		//Ask for the mean for the random numbers of inter arrival time
		cout << "Enter first inter-arrival-time period: \nfrom:";
		cin >> a2;
		//	//Ask for the mean for the random numbers of server service time
		cout << "Enter second inter-arrival-time period: \n";
		cin >> b2;
		STAtS[1] = uniForm_law(a1, b1, rand_no_of_SST[1]);

		break;
	case'3':
		//To enter number of rows
		cout << "Enter_Num_arrival_interival\n";
		cin >> number_interival_2;
		for (int i = 1; i <= number_interival_2; i++) {
			cout << "Enter_Num_between_process: " << i << ':' << "and" << i + 1 << '\n';
			cin >> Time_between_process2[i];
		}
		//To_get_probability
		for (int i = 1; i <= number_interival_2; i++)
		{
			cout << "enter number of probability: " << i << ':' << "and" << i + 1 << '\n';
			cin >> probability_2[i];
			cumulative_2 += probability_2[i];
			cumulative_array2[i] = cumulative_2;
		}


		//to get numbers of start and end
		num_ass_1_start2[1] = 0.01;
		num_ass_1_end2[1] = cumulative_array2[1];
		for (int i = 2; i <= number_interival_2; i++)
		{
			num_ass_1_end2[i] = cumulative_array2[i];
			num_ass_1_start2[i] = (num_ass_1_end2[i - 1] + 0.01);
			if (num_ass_1_end2[i] == 1) {
				num_ass_1_end2[i] = 0.00;
			}

		}



		STAtS[1] = emparical_law_serv(rand_no_of_SST[1]);
		break;
	default:
		cout << "3nd 3m fat7y\n";
	}
	//----------------------------- 

	arrival_time += IAT[1]; //arrival time

	Arival_T[1] = arrival_time; //arrival time
	//----------------------------- 

	if (arrival_time > server_end)
	{
		Time_SB[1] = arrival_time;
	}
	else
	{
		Time_SB[1] = server_end;
	}

	//----------------------------- 

	server_end = Time_SB[1] + STAtS[1];

	Time_SE[1] = server_end;

	Customer_D[1] = (abs(Arival_T[1] - Time_SB[1]));

	Idle[1] = ((Arival_T[1] - 0));

	//----------------------------- 

	// Print table headers
	cout << setw(17) << left << "r_inter_a_time";
	cout << setw(17) << left << "inter_arr_time";
	cout << setw(17) << left << "arr_time";
	cout << setw(17) << left << "r_server_time";
	cout << setw(17) << left << "serv_t_at_server";
	cout << setw(17) << left << "t_server_b";
	cout << setw(17) << left << "t_server_E";
	cout << setw(17) << left << "customer_delay";
	cout << setw(17) << left << "idle" << endl;

	//-----------------------------

	// Print table rows
	Print_output(rand_no_of_IAT[1]);
	Print_output(IAT[1]);
	Print_output(Arival_T[1]);
	Print_output(rand_no_of_SST[1]);
	Print_output(STAtS[1]);
	Print_output(Time_SB[1]);
	Print_output(Time_SE[1]);
	Print_output(Customer_D[1]);
	Print_output(Idle[1]);
	cout << "\n";

	//-----------------------------

	//-----------------------------
	for (int i = 2; i <= no_customers; i++)
	{
		switch (choose_law_customer) {
		case'1':

			IAT[i] = (exponential_law(mean_custmoers, rand_no_of_IAT[i]));

			break;
		case'2':

			IAT[i] = (uniForm_law(a1, b1, rand_no_of_IAT[i]));
			break;
		case'3':
			IAT[i] = emparical_law(rand_no_of_IAT[i]);
			break;
		default:
			cout << "3nd 3m fat7y\n";
		}
		//----------------------------- 	
		arrival_time += IAT[i]; //arrival time

		Arival_T[i] = arrival_time; //arrival time

		switch (choose_law_server) {
		case'1':


			STAtS[i] = exponential_law(mean_service, rand_no_of_SST[i]);

			break;
		case'2':

			STAtS[i] = uniForm_law(a1, b1, rand_no_of_SST[i]);

			break;
		case'3':
			STAtS[i] = emparical_law_serv(rand_no_of_SST[i]);
			break;
		default:
			cout << "3nd 3m fat7y\n";
		}
		if (arrival_time > server_end)
		{
			Time_SB[i] = arrival_time;
		}
		else
		{
			Time_SB[i] = server_end;
		}
		if (Time_SB[i] > server_end)
		{
			Idle[i] = (abs(Time_SB[i] - server_end));
		}
		else
		{
			Idle[i] = 0;
		}
		server_end = Time_SB[i] + STAtS[i];
		Time_SE[i] = server_end;
		Customer_D[i] = (abs(Arival_T[i] - Time_SB[i]));



		Print_output(rand_no_of_IAT[i]);
		Print_output(IAT[i]);
		Print_output(Arival_T[i]);
		Print_output(rand_no_of_SST[i]);
		Print_output(STAtS[i]);
		Print_output(Time_SB[i]);
		Print_output(Time_SE[i]);
		Print_output(Customer_D[i]);
		Print_output(Idle[i]);
		cout << "\n";

	}
	tn = Time_SE[no_customers];
	for (int k = 1; k < no_customers; k++)
	{
		Sum_idle += Idle[k];
	}
	for (int k = 1; k < no_customers; k++)
	{
		Sum_Delay += Customer_D[k];
	}

	exp_avg_delay = Sum_Delay / no_customers;
	q_length = Sum_Delay / tn;
	uti_server = (tn - Sum_idle) / tn;




	cout << setw(102) << left << "";
	cout << setw(17) << left << "TN";
	cout << setw(17) << left << "Sum_Delay";
	cout << setw(17) << left << "Sum_idle" << endl;

	cout << setw(119) << left << "";
	cout << setw(17) << left << Sum_Delay;
	cout << setw(17) << left << Sum_idle << endl;

	cout << "Expected AVG Delay: " << exp_avg_delay << endl
		<< "Queue Lenght: " << q_length << endl
		<< "Expected Utilization Of Server: " << uti_server << endl << endl;



}


void series_double_server() {


	cout << "Enter Number of customer \n";
	cin >> no_customers;
	cout << "-----------------------------------\n";
	//----------------------------- 
	for (int x = 1; x <= no_customers; x++)
	{
		cout << "Enter Random Num inter_arrival_time  " << x << endl;
		cin >> rand_no_of_IAT[x];
	}
	//----------------------------- 

	cout << "-----------------------------------\n";

	//----------------------------- 

	cout << "-----------------------------------\n";

	cout << "Select Law You Want To To Calculate Inter Arr Time......\n";
	cout << "1- exponential Law\n";
	cout << "2- uniForm Law\n";
	cout << "3- EmparicaL Law\n";
	cin >> choose_law_customer;
	switch (choose_law_customer) {
	case'1':
		//Ask for the mean for the randome numbers of inter arrival time

		cout << "Enter Mean Random Num inter_arrival_time \n";

		cin >> mean_custmoers;

		cout << "-----------------------------------\n";

		IAT[1] = (exponential_law(mean_custmoers, rand_no_of_IAT[1]));

		break;
	case'2':
		//Ask for the mean for the random numbers of inter arrival time

		cout << "Enter first inter-arrival-time period: \nfrom: ";

		cin >> a1;

		//	//Ask for the mean for the random numbers of server service time

		cout << "Enter second inter-arrival-time period: \n to: ";

		cin >> b1;

		IAT[1] = (uniForm_law(a1, b1, rand_no_of_IAT[1]));
		break;
	case'3':
		//To enter number of rows
		cout << "Enter_Num_arrival_interival\n";
		cin >> number_interival_1;
		for (int i = 1; i <= number_interival_1; i++) {
			cout << "Enter_Num_between_process: " << i << ':' << "and" << i + 1 << '\n';
			cin >> Time_between_process[i];
		}
		//To_get_probability
		for (int i = 1; i <= number_interival_1; i++)
		{
			cout << "enter number of probability: " << i << ':' << "and" << i + 1 << '\n';
			cin >> probability_1[i];
			cumulative_1 += probability_1[i];
			cumulative_array[i] = cumulative_1;
		}


		//to get numbers of start and end
		num_ass_1_start[1] = 0.01;
		num_ass_1_end[1] = cumulative_array[1];
		for (int i = 2; i <= number_interival_1; i++)
		{
			num_ass_1_end[i] = cumulative_array[i];
			num_ass_1_start[i] = (num_ass_1_end[i - 1] + 0.01);
			if (num_ass_1_end[i] == 1) {
				num_ass_1_end[i] = 0.00;
			}

		}



		IAT[1] = emparical_law(rand_no_of_IAT[1]);



		break;
	default:
		cout << "3nd 3m fat7y\n";
	}


	//-----------------------------------------------------

	for (int x = 1; x <= no_customers; x++)
	{
		cout << "Enter  Random Num  of server 1   " << x << endl;
		cin >> rand_no_of_SST[x];


	}
	cout << "-----------------------------------\n";

	//----------------------------- 

	// server 1
	cout << "Select Law You Want To Use To Calculate Service Time At Server 1......\n";
	cout << "1- exponential Law\n";
	cout << "2- uniForm Law\n";
	cout << "3- EmparicaL Law\n";
	cin >> choose_law_server;
	switch (choose_law_server) {
	case'1':

		//	//Ask for the mean for the randome numbers of server service time

		cout << "Enter Mean Random Num Server 1 Service Time \n";

		cin >> mean_service;

		cout << "-----------------------------------\n";

		STAtS[1] = exponential_law(mean_service, rand_no_of_SST[1]);

		break;
	case'2':
		//Ask for the mean for the random numbers of inter arrival time
		cout << "Enter first inter-arrival-time period: \nfrom:";
		cin >> a2;
		//	//Ask for the mean for the random numbers of server service time
		cout << "Enter second inter-arrival-time period: \n";
		cin >> b2;
		STAtS[1] = uniForm_law(a2, b2, rand_no_of_SST[1]);

		break;
	case'3':

		//To enter number of rows
		cout << "Enter_Num_arrival_interival\n";
		cin >> number_interival_2;
		for (int i = 1; i <= number_interival_2; i++) {
			cout << "Enter_Num_between_process: " << i << ':' << "and" << i + 1 << '\n';
			cin >> Time_between_process2[i];
		}
		//To_get_probability
		for (int i = 1; i <= number_interival_2; i++)
		{
			cout << "enter number of probability: " << i << ':' << "and" << i + 1 << '\n';
			cin >> probability_2[i];
			cumulative_2 += probability_2[i];
			cumulative_array2[i] = cumulative_2;
		}


		//to get numbers of start and end
		num_ass_1_start2[1] = 0.01;
		num_ass_1_end2[1] = cumulative_array2[1];
		for (int i = 2; i <= number_interival_2; i++)
		{
			num_ass_1_end2[i] = cumulative_array2[i];
			num_ass_1_start2[i] = (num_ass_1_end2[i - 1] + 0.01);
			if (num_ass_1_end2[i] == 1) {
				num_ass_1_end2[i] = 0.00;
			}

		}



		STAtS[1] = emparical_law_serv(rand_no_of_SST[1]);



		break;
	default:
		cout << "3nd 3m fat7y\n";
	}

	//-----------------------------------------

	for (int x = 1; x <= no_customers; x++)
	{
		cout << "Enter  Random Num  of server 2  " << x << endl;
		cin >> rand_no_of_SST2[x];


	}
	cout << "-----------------------------------\n";

	//----------------------------- 

	//server 2
	cout << "Select Law You Want To Use To Calculate Service Time At Server 2......\n";
	cout << "1- exponential Law\n";
	cout << "2- uniForm Law\n";
	cout << "3- EmparicaL Law\n";
	cin >> choose_law_server2;
	switch (choose_law_server2) {
	case'1':

		//	//Ask for the mean for the randome numbers of server service time

		cout << "Enter Mean Random Num Server 2 Service Time \n";

		cin >> mean_service2;

		cout << "-----------------------------------\n";

		STAtS2[1] = exponential_law(mean_service2, rand_no_of_SST2[1]);

		break;
	case'2':
		//Ask for the mean for the random numbers of inter arrival time
		cout << "Enter first inter-arrival-time period: \nfrom:";
		cin >> a3;
		//	//Ask for the mean for the random numbers of server service time
		cout << "Enter second inter-arrival-time period: \n";
		cin >> b3;
		STAtS2[1] = uniForm_law(a3, b3, rand_no_of_SST2[1]);

		break;
	case'3':
		//To enter number of rows
		cout << "Enter_Num_arrival_interival\n";
		cin >> number_interival_3;
		for (int i = 1; i <= number_interival_3; i++) {
			cout << "Enter_Num_between_process: " << i << ':' << "and" << i + 1 << '\n';
			cin >> Time_between_process3[i];
		}
		//To_get_probability
		for (int i = 1; i <= number_interival_3; i++)
		{
			cout << "enter number of probability: " << i << ':' << "and" << i + 1 << '\n';
			cin >> probability_3[i];
			cumulative_3 += probability_3[i];
			cumulative_array3[i] = cumulative_3;
		}


		//to get numbers of start and end
		num_ass_1_start3[1] = 0.01;
		num_ass_1_end3[1] = cumulative_array3[1];
		for (int i = 2; i <= number_interival_3; i++)
		{
			num_ass_1_end3[i] = cumulative_array3[i];
			num_ass_1_start3[i] = (num_ass_1_end3[i - 1] + 0.01);
			if (num_ass_1_end3[i] == 1) {
				num_ass_1_end3[i] = 0.00;
			}

		}



		STAtS2[1] = emparical_law_serv2(rand_no_of_SST2[1]);
		break;
	default:
		cout << "3nd 3m fat7y\n";
	}

	//-----------------------------------------------------
	double server_end2 = 0;
	double server_end = 0;
	double arrival_time = 0;
	double delay = 0;
	//----------------------------- 

	arrival_time += IAT[1]; //arrival time

	Arival_T[1] = arrival_time; //arrival time





	//-----------------------------
	//server 1

	if (arrival_time > server_end)
	{
		Time_SB[1] = arrival_time;
	}
	else
	{
		Time_SB[1] = server_end;
	}

	//----------------------------- 

	server_end = Time_SB[1] + STAtS[1];

	Time_SE[1] = server_end;


	if (server_end > server_end2)
	{
		Time_SB2[1] = server_end;
	}
	else
	{
		Time_SB2[1] = server_end2;
	}

	//-----------------------------  

	server_end2 = Time_SB2[1] + STAtS2[1];

	Time_SE2[1] = server_end2;

	//-------------------------------

	Idle[1] = ((Arival_T[1] - 0));
	Idle2[1] = (Time_SE[1] - 0);

	//-------------------------------

	Customer_D[1] = 0;
	Customer_D2[1] = 0;
	delay = Customer_D[1] + Customer_D2[1];
	Customer_D_T[1] = delay;

	//-------------------------------

	// Print table headers
	cout << setw(17) << left << "rand_i_arr_t";
	cout << setw(17) << left << "inter_arr_t";
	cout << setw(17) << left << "arr_time";
	cout << setw(17) << left << "r_server_1";
	cout << setw(17) << left << "service_T_1";
	cout << setw(17) << left << "s_begin_1";
	cout << setw(17) << left << "s_end_1";
	cout << setw(17) << left << "idle_1";
	cout << setw(17) << left << "r_server_2";
	cout << setw(17) << left << "service_T_2";
	cout << setw(17) << left << "s_begin_2";
	cout << setw(17) << left << "s_end_2";
	cout << setw(17) << left << "idle_2";
	cout << setw(17) << left << "Total_delay" << endl;

	//-----------------------------

	// Print table rows
	Print_output(rand_no_of_IAT[1]);
	Print_output(IAT[1]);
	Print_output(Arival_T[1]);
	Print_output(rand_no_of_SST[1]);
	Print_output(STAtS[1]);
	Print_output(Time_SB[1]);
	Print_output(Time_SE[1]);
	Print_output(Idle[1]);
	Print_output(rand_no_of_SST2[1]);
	Print_output(STAtS2[1]);
	Print_output(Time_SB2[1]);
	Print_output(Time_SE2[1]);
	Print_output(Idle2[1]);
	Print_output(Customer_D_T[1]);
	cout << "\n";

	for (int i = 2; i <= no_customers; i++)
	{
		switch (choose_law_customer) {
		case'1':

			IAT[i] = (exponential_law(mean_custmoers, rand_no_of_IAT[i]));

			break;
		case'2':

			IAT[i] = (uniForm_law(a1, b1, rand_no_of_IAT[i]));

			break;
		case'3':

			IAT[i] = emparical_law(rand_no_of_IAT[i]);
			break;
		default:
			cout << "3nd 3m fat7y\n";
		}

		arrival_time += IAT[i]; //arrival time

		Arival_T[i] = arrival_time; //arrival time

		// server 1
		switch (choose_law_server) {
		case'1':

			STAtS[i] = exponential_law(mean_service, rand_no_of_SST[i]);

			break;
		case'2':

			STAtS[i] = uniForm_law(a2, b2, rand_no_of_SST[i]);

			break;
		case'3':


			STAtS[i] = emparical_law_serv(rand_no_of_SST[i]);
			break;
		default:
			cout << "3nd 3m fat7y\n";
		}

		//server 2
		switch (choose_law_server2) {
		case'1':

			STAtS2[i] = exponential_law(mean_service2, rand_no_of_SST2[i]);

			break;
		case'2':

			STAtS2[i] = uniForm_law(a3, b3, rand_no_of_SST2[i]);

			break;
		case'3':

			STAtS2[i] = emparical_law_serv2(rand_no_of_SST2[i]);
			break;
		default:
			cout << "3nd 3m fat7y\n";
		}

		//----------------------------- 
		if (arrival_time > server_end)
		{
			Time_SB[i] = arrival_time;
		}
		else
		{
			Time_SB[i] = server_end;
		}


		if (Time_SB[i] > server_end)
		{
			Idle[i] = (abs(Time_SB[i] - server_end));
		}
		else
		{
			Idle[i] = 0;
		}
		//----------------------------- 
		server_end = Time_SB[i] + STAtS[i];

		Time_SE[i] = (server_end);
		//----------------------------- 

		if (server_end > server_end2)
		{
			Time_SB2[i] = (server_end);
		}
		else
		{
			Time_SB2[i] = (server_end2);
		}
		//----------------------------- 

		if (Time_SB2[i] > server_end2)
		{
			Idle2[i] = (abs(Time_SB2[i] - server_end2));
		}
		else
		{
			Idle2[i] = 0;
		}

		//----------------------------- 

		server_end2 = Time_SB2[i] + STAtS2[i];

		Time_SE2[i] = (server_end2);

		//-------------------------------

		Customer_D[i] = (abs(Arival_T[i] - Time_SB[i]));
		Customer_D2[i] = (abs(Time_SE[i] - Time_SB2[i]));
		delay = Customer_D[i] + Customer_D2[i];
		Customer_D_T[i] = (delay);

		//-------------------------------

		// Print table rows
		Print_output(rand_no_of_IAT[i]);
		Print_output(IAT[i]);
		Print_output(Arival_T[i]);
		Print_output(rand_no_of_SST[i]);
		Print_output(STAtS[i]);
		Print_output(Time_SB[i]);
		Print_output(Time_SE[i]);
		Print_output(Idle[i]);
		Print_output(rand_no_of_SST2[i]);
		Print_output(STAtS2[i]);
		Print_output(Time_SB2[i]);
		Print_output(Time_SE2[i]);
		Print_output(Idle2[i]);
		Print_output(Customer_D_T[i]);
		cout << "\n";

	}
	tn = Time_SE2[no_customers];
	for (int k = 1; k < no_customers; k++)
	{
		Sum_idle += Idle[k];
	}
	for (int k = 1; k < no_customers; k++)
	{
		Sum_idle2 += Idle2[k];
	}
	for (int k = 1; k < no_customers; k++)
	{
		Sum_Delay += Customer_D_T[k];
	}

	exp_avg_delay = Sum_Delay / no_customers;
	q_length = Sum_Delay / tn;
	uti_server = (tn - Sum_idle) / tn;
	uti_server2 = (tn - Sum_idle2) / tn;





	cout << setw(119) << left << "";
	cout << setw(17) << left << "Sum_idle_1";
	cout << setw(34) << left << "";
	cout << setw(17) << left << "TN";
	cout << setw(17) << left << "Sum_idle_2";
	cout << setw(17) << left << "Sum_Delay" << endl;


	cout << setw(119) << left << "";
	cout << setw(17) << left << Sum_idle;
	cout << setw(51) << left << "";
	cout << setw(17) << left << Sum_idle2;
	cout << setw(17) << left << Sum_Delay << endl;


	cout << "Expected AVG Delay: " << exp_avg_delay << endl
		<< "Queue Lenght: " << q_length << endl
		<< "Expected Utilization Of Server: " << uti_server << endl
		<< "Expected Utilization Of Server 2: " << uti_server2 << endl << endl;


}
void parallel_double_server() {

	cout << "Enter Number of customer \n";
	cin >> no_customers;
	cout << "-----------------------------------\n";
	//----------------------------- 
	for (int x = 1; x <= no_customers; x++)
	{
		cout << "Enter Random Num inter_arrival_time  " << x << endl;
		cin >> rand_no_of_IAT[x];
				}
	//----------------------------- 

	cout << "-----------------------------------\n";

	//----------------------------- 

	cout << "-----------------------------------\n";

	cout << "Select Law You Want To To Calculate Inter Arr Time......\n";
	cout << "1- exponential Law\n";
	cout << "2- uniForm Law\n";
	cout << "3- EmparicaL Law\n";
	cin >> choose_law_customer;
	switch (choose_law_customer) {
	case'1':
		//Ask for the mean for the randome numbers of inter arrival time

		cout << "Enter Mean Random Num inter_arrival_time \n";

		cin >> mean_custmoers;

		cout << "-----------------------------------\n";

		IAT[1] = (exponential_law(mean_custmoers, rand_no_of_IAT[1]));

		break;
	case'2':
		//Ask for the mean for the random numbers of inter arrival time

		cout << "Enter first inter-arrival-time period: \nfrom: ";

		cin >> a1;

		//	//Ask for the mean for the random numbers of server service time

		cout << "Enter second inter-arrival-time period: \n to: ";

		cin >> b1;

		IAT[1] = (uniForm_law(a1, b1, rand_no_of_IAT[1]));
		break;
	case'3':
		//To enter number of rows
		cout << "Enter_Num_arrival_interival\n";
		cin >> number_interival_1;
		for (int i = 1; i <= number_interival_1; i++) {
			cout << "Enter_Num_between_process: " << i << ':' << "and" << i + 1 << '\n';
			cin >> Time_between_process[i];
		}
		//To_get_probability
		for (int i = 1; i <= number_interival_1; i++)
		{
			cout << "enter number of probability: " << i << ':' << "and" << i + 1 << '\n';
			cin >> probability_1[i];
			cumulative_1 += probability_1[i];
			cumulative_array[i] = cumulative_1;
		}


		//to get numbers of start and end
		num_ass_1_start[1] = 0.01;
		num_ass_1_end[1] = cumulative_array[1];
		for (int i = 2; i <= number_interival_1; i++)
		{
			num_ass_1_end[i] = cumulative_array[i];
			num_ass_1_start[i] = (num_ass_1_end[i - 1] + 0.01);

		}



		IAT[1] = emparical_law(rand_no_of_IAT[1]);


		break;
	default:
		cout << "3nd 3m fat7y\n";
	}


	//-----------------------------------------------------

	for (int x = 1; x <= no_customers; x++)
	{
		cout << "Enter  Random Num  of servers   " << x << endl;
		cin >> rand_no_of_SST[x];


	}
	cout << "-----------------------------------\n";

	//----------------------------- 

	// server 1
	cout << "Select Law You Want To Use To Calculate Service Time At Server 1......\n";
	cout << "1- exponential Law\n";
	cout << "2- uniForm Law\n";
	cout << "3- EmparicaL Law\n";
	cin >> choose_law_server;
	switch (choose_law_server) {
	case'1':

		//	//Ask for the mean for the randome numbers of server service time

		cout << "Enter Mean Random Num Server 1 Service Time \n";

		cin >> mean_service;

		cout << "-----------------------------------\n";

		STAtS[1] = exponential_law(mean_service, rand_no_of_SST[1]);

		break;
	case'2':
		//Ask for the mean for the random numbers of inter arrival time
		cout << "Enter first inter-arrival-time period: \nfrom:";
		cin >> a2;
		//	//Ask for the mean for the random numbers of server service time
		cout << "Enter second inter-arrival-time period: \n";
		cin >> b2;
		STAtS[1] = uniForm_law(a2, b2, rand_no_of_SST[1]);

		break;
	case'3':
		//To enter number of rows
		cout << "Enter_Num_arrival_interival\n";
		cin >> number_interival_2;
		for (int i = 1; i <= number_interival_2; i++) {
			cout << "Enter_Num_between_process: " << i << ':' << "and" << i + 1 << '\n';
			cin >> Time_between_process2[i];
		}
		//To_get_probability
		for (int i = 1; i <= number_interival_2; i++)
		{
			cout << "enter number of probability: " << i << ':' << "and" << i + 1 << '\n';
			cin >> probability_2[i];
			cumulative_2 += probability_2[i];
			cumulative_array2[i] = cumulative_2;
		}


		//to get numbers of start and end
		num_ass_1_start2[1] = 0.01;
		num_ass_1_end2[1] = cumulative_array2[1];
		for (int i = 2; i <= number_interival_2; i++)
		{
			num_ass_1_end2[i] = cumulative_array2[i];
			num_ass_1_start2[i] = (num_ass_1_end2[i - 1] + 0.01);
		

		}
		STAtS[1] = emparical_law_serv(rand_no_of_SST[1]);

		break;
	default:
		cout << "3nd 3m fat7y\n";
	}


	//-----------------------------------------------------


	//server 2
	cout << "Select Law You Want To Use To Calculate Service Time At Server 2......\n";
	cout << "1- exponential Law\n";
	cout << "2- uniForm Law\n";
	cout << "3- EmparicaL Law\n";
	cin >> choose_law_server2;
	switch (choose_law_server2) {
	case'1':

		//	//Ask for the mean for the randome numbers of server service time

		cout << "Enter Mean Random Num Server 2 Service Time \n";

		cin >> mean_service2;

		cout << "-----------------------------------\n";

		//STAtS2[1] = exponential_law(mean_service2, rand_no_of_SST[1]);

		break;
	case'2':
		//Ask for the mean for the random numbers of inter arrival time
		cout << "Enter first inter-arrival-time period: \nfrom:";
		cin >> a3;
		//	//Ask for the mean for the random numbers of server service time
		cout << "Enter second inter-arrival-time period: \n";
		cin >> b3;
		//STAtS2[1] = uniForm_law(a3, b3, rand_no_of_SST[1]);

		break;
	case'3':
		//To enter number of rows
		cout << "Enter_Num_arrival_interival\n";
		cin >> number_interival_3;
		for (int i = 1; i <= number_interival_3; i++) {
			cout << "Enter_Num_between_process: " << i << ':' << "and" << i + 1 << '\n';
			cin >> Time_between_process3[i];
		}
		//To_get_probability
		for (int i = 1; i <= number_interival_3; i++)
		{
			cout << "enter number of probability: " << i << ':' << "and" << i + 1 << '\n';
			cin >> probability_3[i];
			cumulative_3 += probability_3[i];
			cumulative_array3[i] = cumulative_3;
		}


		//to get numbers of start and end
		num_ass_1_start3[1] = 0.01;
		num_ass_1_end3[1] = cumulative_array3[1];
		for (int i = 2; i <= number_interival_3; i++)
		{
			num_ass_1_end3[i] = cumulative_array3[i];
			num_ass_1_start3[i] = (num_ass_1_end3[i - 1] + 0.01);

		}



		break;
	default:
		cout << "3nd 3m fat7y\n";
	}


	//-----------------------------------------------------
	double server_end2 = 0;
	double server_end = 0;
	double arrival_time = 0;
	double delay = 0;
	//-----------------------------------------------------

	arrival_time += IAT[1]; //arrival time

	Arival_T[1] = arrival_time; //arrival time

	//-----------------------------------------------------

	//server 1

	if (arrival_time > server_end)
	{
		Time_SB[1] = arrival_time;
	}
	else
	{
		Time_SB[1] = server_end;
	}

	//----------------------------- 

	server_end = Time_SB[1] + STAtS[1];

	Time_SE[1] = server_end;
	Time_SE_temp = server_end;

	//-----------------------------

	Idle[1] = ((Arival_T[1] - 0));
	Customer_D[1] = 0;
	//-----------------------------
	STAtS2[1] = 0;
	Time_SB2[1] = 0;
	Idle2[1] = 0;
	Time_SE2[1] = 0;
	//-------------------------------

	// Print table headers
	cout << setw(17) << left << "rand_i_arr_t";
	cout << setw(17) << left << "inter_arr_t";
	cout << setw(17) << left << "arr_time";
	cout << setw(17) << left << "r_server";
	cout << setw(17) << left << "service_T_1";
	cout << setw(17) << left << "s_begin_1";
	cout << setw(17) << left << "s_end_1";
	cout << setw(17) << left << "idle_1";
	//cout << setw(17) << left << "r_server_2";
	cout << setw(17) << left << "service_T_2";
	cout << setw(17) << left << "s_begin_2";
	cout << setw(17) << left << "s_end_2";
	cout << setw(17) << left << "idle_2";
	cout << setw(17) << left << "Delay" << endl;

	//-----------------------------

	// Print table rows
	Print_output(rand_no_of_IAT[1]);
	Print_output(IAT[1]);
	Print_output(Arival_T[1]);
	Print_output(rand_no_of_SST[1]);
	Print_output(STAtS[1]);
	Print_output(Time_SB[1]);
	Print_output(Time_SE[1]);
	Print_output(Idle[1]);
	//Print_output(rand_no_of_SST2[1]);
	Print_output(STAtS2[1]);
	Print_output(Time_SB2[1]);
	Print_output(Time_SE2[1]);
	Print_output(Idle2[1]);
	Print_output(Customer_D[1]);
	cout << "\n";

	for (int i = 2; i <= no_customers; i++)
	{
		switch (choose_law_customer) {
		case'1':

			IAT[i] = (exponential_law(mean_custmoers, rand_no_of_IAT[i]));

			break;
		case'2':

			IAT[i] = (uniForm_law(a1, b1, rand_no_of_IAT[i]));

			break;
		case'3':
			IAT[i] = emparical_law(rand_no_of_IAT[i]);

			break;
		default:
			cout << "3nd 3m fat7y\n";
		}
		//-----------------------------------------------------

		arrival_time += IAT[i]; //arrival time

		Arival_T[i] = arrival_time; //arrival time

		//-----------------------------------------------------

		if (Time_SE2_temp < Time_SE_temp) {

			switch (choose_law_server2) {
			case'1':

				STAtS2[i] = exponential_law(mean_service2, rand_no_of_SST[i]);

				break;

			case'2':

				STAtS2[i] = uniForm_law(a3, b3, rand_no_of_SST[i]);

				break;

			case'3':
				STAtS2[i] = emparical_law_serv2(rand_no_of_SST[i]);

				break;
			default:
				cout << "3nd 3m fat7y\n";
			}

			//-----------------------------------------------------

			if (Arival_T[i] > Time_SE2_temp) {
				Time_SB2[i] = Arival_T[i];
			}
			else {
				Time_SB2[i] = Time_SE2_temp;
			}

			//-----------------------------------------------------

			if (Time_SB2[i] > Time_SE2_temp)
			{
				Idle2[i] = (abs(Time_SB2[i] - Time_SE2_temp));
			}
			else
			{
				Idle2[i] = 0;
			}

			//-----------------------------------------------------

			Time_SE2[i] = Time_SB2[i] + STAtS2[i];
			Time_SE2_temp = Time_SE2[i];
			Customer_D[i] = abs(Time_SB2[i] - Arival_T[i]);

			//-----------------------------------------------------

			STAtS[i] = 0;
			Time_SB[i] = 0;
			Idle[i] = 0;
			Time_SE[i] = 0;

			//-------------------------------


		}
		else if (Time_SE2_temp >= Time_SE_temp) {
			switch (choose_law_server) {
			case'1':

				STAtS[i] = exponential_law(mean_service, rand_no_of_SST[i]);

				break;
			case'2':

				STAtS[i] = uniForm_law(a2, b2, rand_no_of_SST[i]);

				break;
			case'3':
				STAtS[i] = emparical_law_serv(rand_no_of_SST[i]);

				break;
			default:
				cout << "3nd 3m fat7y\n";
			}

			//-----------------------------------------------------

			if (Arival_T[i] > Time_SE_temp)
			{
				Time_SB[i] = Arival_T[i];
			}
			else
			{
				Time_SB[i] = Time_SE_temp;
			}
			//-----------------------------------------------------

			if (Time_SB[i] > Time_SE_temp)
			{
				Idle[i] = (abs(Time_SB[i] - Time_SE_temp));
			}
			else
			{
				Idle[i] = 0;
			}
			//-----------------------------

			Time_SE[i] = Time_SB[i] + STAtS[i];
			Time_SE_temp = Time_SE[i];

			//----------------------------- 

			Customer_D[i] = abs(Time_SB[i] - Arival_T[i]);

			//----------------------------- 

			STAtS2[i] = 0;
			Time_SB2[i] = 0;
			Idle2[i] = 0;
			Time_SE2[i] = 0;

			//-------------------------------

		};
		if (Time_SE2[no_customers] == 0)
		{
			Idle2[no_customers] = abs(Idle2[no_customers - 1] - Idle[no_customers]);
		}



		// Print table rows
		Print_output(rand_no_of_IAT[i]);
		Print_output(IAT[i]);
		Print_output(Arival_T[i]);
		Print_output(rand_no_of_SST[i]);
		Print_output(STAtS[i]);
		Print_output(Time_SB[i]);
		Print_output(Time_SE[i]);
		Print_output(Idle[i]);
		//Print_output(rand_no_of_SST2[1]);
		Print_output(STAtS2[i]);
		Print_output(Time_SB2[i]);
		Print_output(Time_SE2[i]);
		Print_output(Idle2[i]);
		Print_output(Customer_D[i]);
		cout << "\n";


	}

	tn = Time_SE2[no_customers];
	for (int k = 1; k < no_customers; k++)
	{
		Sum_idle += Idle[k];
	}
	for (int k = 1; k < no_customers; k++)
	{
		Sum_idle2 += Idle2[k];
	}
	for (int k = 1; k < no_customers; k++)
	{
		Sum_Delay += Customer_D[k];
	}

	exp_avg_delay = Sum_Delay / no_customers;
	q_length = Sum_Delay / tn;
	uti_server = (tn - Sum_idle) / tn;
	uti_server2 = (tn - Sum_idle2) / tn;





	cout << setw(119) << left << "";
	cout << setw(17) << left << "Sum_idle_1";
	cout << setw(34) << left << "";
	cout << setw(17) << left << "TN";
	cout << setw(17) << left << "Sum_idle_2";
	cout << setw(17) << left << "Sum_Delay" << endl;


	cout << setw(119) << left << "";
	cout << setw(17) << left << Sum_idle;
	cout << setw(51) << left << "";
	cout << setw(17) << left << Sum_idle2;
	cout << setw(17) << left << Sum_Delay << endl;


	cout << "Expected AVG Delay: " << exp_avg_delay << endl
		<< "Queue Lenght: " << q_length << endl
		<< "Expected Utilization Of Server: " << uti_server << endl
		<< "Expected Utilization Of Server 2: " << uti_server2 << endl << endl;


}



int main() {
	cout << setw(4) << ".........Welcome To Your Program........." << '\n';
	cout << "choose Single Server OR Double Server\n";
	cout << "1-Sinle Server\n2-Double Server\n";
	char choose;
	cin >> choose;
	switch (choose) {
	case '1':
		single_server();

		break;
	case '2':
		cout << "1-Series Double Server\n2-Parallel Double Server\n";
		cin >> choose;
		switch (choose) {
		case '1':
			series_double_server();
			break;
		case '2':
			parallel_double_server();
			break;
		default:
			cout << "3nd 3m 7mada" << endl;
			break;
		}
	}
	return 0;


}