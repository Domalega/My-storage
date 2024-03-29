#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>
#include <signal.h>
#include <iostream>
#include <algorithm>
#include <string>

#define BUFLEN 255

using namespace std;


//CodeWords - ключивые слова карт, используется для вывода
//masOfCards - хранит количество использованных карт (что бы не было привышение 4 штук) 	
string CodeWords[15] = {"0","1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "jack", "queen", "king", "ace"};
int ValueOfWords[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 2, 3, 4};

	
void Help(){
	cout << "Two cards are dealt to the table, visible to both players.\n\
After that, everyone in turn can either draw one more card, or stop drawing cards.\n\
The game will stop when both players say stop or both of them take cards on more then 21 points.\n\n";
}

void ClientStart(){
	char buf[BUFLEN];
	char buf1[BUFLEN];
	int sockClient, sockServer, port;
	struct sockaddr_in clientAddr, servAddr;
	struct hostent *hp;
	string value = " ";
	
	string ip;
    cout << "Input ip: ";
    cin >> ip;
    cout << "Input port: ";
    cin >> port;
	
	bzero((char *) &clientAddr, sizeof(clientAddr));
	
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(0);
	clientAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	hp = gethostbyname(ip.c_str());
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(port);
	bcopy(hp->h_addr, &servAddr.sin_addr, hp->h_length);
	
	sockClient = socket(AF_INET, SOCK_STREAM, 0);
	bind(sockClient, (struct sockaddr *)&clientAddr, sizeof(clientAddr));
	connect(sockClient, (struct sockaddr *)&servAddr, sizeof(servAddr));
	
	char TempBuf[BUFLEN];
	string CardsOnTable[2];

	int SumClinet = 0, temp;
	for(;;){
		bzero(buf, BUFLEN);		
		recv(sockClient, buf, BUFLEN, 0);
		recv(sockClient, buf1, BUFLEN, 0);
		cout << "\nStart`s cards :\n" << buf <<  "\n" << buf1 << "\n";
		
		CardsOnTable[0] = string(buf);
		CardsOnTable[1] = string(buf1);
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 15; j++)
				if(CardsOnTable[i] == CodeWords[j])
					SumClinet += ValueOfWords[j];
									
		string choice;
		Repeat:
			if(SumClinet < 21){
				cout << "Take card or Stop?\n";
				cin >> choice;
				// to lowercase commands
				transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
				if(choice == "stop"){
					cout << "Client : " + choice + "\n";
					strcpy(buf, choice.c_str());
					send(sockClient, buf, BUFLEN, 0);
			
					break;
				}
				
				if(choice == "take"){
					temp = 6 + rand() % (14 - 6);
					cout << "You Take" << "\n" << CodeWords[temp] << "\n";
					SumClinet += ValueOfWords[temp];
					cout << "Yours count" << "\n" << SumClinet << "\n";
					strcpy(buf, choice.c_str());
					
					goto Repeat;
				}
			}
			
			else{
				cout << "You can`t take another card!\n";
				choice = "stop";
				strcpy(buf, choice.c_str());
				send(sockClient, buf, BUFLEN, 0);

				break;			
			}

	}
	
	bzero(buf, BUFLEN);	
	string TempData = to_string(SumClinet);
	copy(TempData.begin(), TempData.end(), buf);
	send(sockClient, buf, BUFLEN, 0);
	bzero(buf, BUFLEN);
	recv(sockClient, buf, BUFLEN, 0);
	cout << buf << "\n";
	close(sockClient);
}

void ServerStart(){
	int sockServer, sockClient;
	bool flag = true, flagnew = true;
	pid_t pid;
	struct sockaddr_in servAddr, clientAddr;
	sockaddr_in addr;
	bzero((char*) &servAddr, sizeof(servAddr));
	bzero((char*) &clientAddr, sizeof(clientAddr));
	unsigned int length = sizeof(servAddr);
	socklen_t addr_len = sizeof(struct sockaddr_in);
	
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_port = 0;
	
	sockServer = socket(AF_INET, SOCK_STREAM, 0);
	bind(sockServer, (struct sockaddr*)&servAddr, sizeof(servAddr));
	getsockname(sockServer, (struct sockaddr *)&servAddr, &addr_len);
	getsockname(sockClient, (struct sockaddr *)&clientAddr, &addr_len);
	listen(sockServer, 1);
	
	printf("Server: № port - %d\n", ntohs(servAddr.sin_port));		
	printf("Server: № Addr - %s\n\n", inet_ntoa(servAddr.sin_addr));
	
	int masOfCards[15], cardsOnTable[15];
	
	int temp, count = 0;
	char bufTempOut[BUFLEN] = {};
	char bufTempOut1[BUFLEN] = {};
	bzero(bufTempOut, BUFLEN);

	for(int i = 0; i < 2; i++){
		temp = 6 + rand() % (14 - 6);
		cardsOnTable[i] = temp;
		masOfCards[temp] += 1;
		count++;
	}
	
	string TempOut = CodeWords[cardsOnTable[0]];
	string TempOut1 = CodeWords[cardsOnTable[1]];
	cout << "Start`s cards : \n" + TempOut + "\n" + TempOut1 + "\n";
	copy(TempOut.begin(), TempOut.end(), bufTempOut);
	copy(TempOut1.begin(), TempOut1.end(), bufTempOut1);


	bool flagStartGame = true;
	for(;;){
		sockClient = accept(sockServer, 0, 0);	
		pid = fork();
		if(pid == 0){
			while(flag){
				char buf[BUFLEN];
				bzero(buf, BUFLEN);
				if(flagStartGame){
					send(sockClient, bufTempOut, BUFLEN, 0);
					send(sockClient, bufTempOut1, BUFLEN, 0);
					flagStartGame = false;
				}
				
				string choice; 
				int SumServer = ValueOfWords[cardsOnTable[0]] + ValueOfWords[cardsOnTable[1]];
				int a = recv(sockClient, buf, BUFLEN, 0);
				if(strcmp(buf, "stop") == 0){
					Repeat:
						if(SumServer < 21){
							cout << "Take card or Stop?\n";
							cin >> choice;
							// to lowercase commands
							transform(choice.begin(), choice.end(), choice.begin(), ::tolower);
							if(choice == "stop"){
								cout << "Server : " + choice + "\n";
								recv(sockClient, buf, BUFLEN, 0);
								string Out = "Server sum: " + to_string(SumServer) + " Client sum: " + string(buf) + "\n";
								
								if(SumServer <= 21 && atoi(string(buf).c_str()) <= 21){
									if(SumServer > atoi(string(buf).c_str()))
										Out += "Server win!\n";
									if(SumServer < atoi(string(buf).c_str()))
										Out += "Client win!\n";
									if(SumServer == atoi(string(buf).c_str()))
										Out += "Draw!\n";
								}
								
								else{
									if(SumServer >= 21 && atoi(string(buf).c_str()) >= 21)
										Out += "mutual defeat!\n";
									if(SumServer <= 21 && atoi(string(buf).c_str()) >= 21)
										Out += "Server win!\n";
									if(SumServer >= 21 && atoi(string(buf).c_str()) <= 21)
										Out += "Client win!\n";															
							
								}
								
								cout << Out;
								bzero(buf, BUFLEN);
								copy(Out.begin(), Out.end(), buf);
								send(sockClient, buf, BUFLEN, 0);
								break;					
							}
					
					
							if(choice == "take"){
								temp = 6 + rand() % (14 - 6);		
								cout << "You Take" << "\n" << CodeWords[temp] << "\n";
								SumServer += ValueOfWords[temp];
								cout << "Yours count" << "\n" << SumServer << "\n";
								goto Repeat;
							}
						}
						
						else{
							cout << "You can`t take another card!\n";
							recv(sockClient, buf, BUFLEN, 0);
							string Out = "Server sum: " + to_string(SumServer) + " Client sum: " + string(buf) + "\n";

						if(SumServer <= 21 && atoi(string(buf).c_str()) <= 21){
							if(SumServer > atoi(string(buf).c_str()))
								Out += "Server win!\n";
							if(SumServer < atoi(string(buf).c_str()))
								Out += "Client win!\n";
							if(SumServer == atoi(string(buf).c_str()))
								Out += "Draw!\n";
						}
						else{
							if(SumServer >= 21 && atoi(string(buf).c_str()) >= 21)
								Out += "mutual defeat!\n";
							if(SumServer <= 21 && atoi(string(buf).c_str()) >= 21)
								Out += "Server win!\n";
							if(SumServer >= 21 && atoi(string(buf).c_str()) <= 21)
								Out += "Client win!\n";															
							
						}
								
							cout << Out;
							bzero(buf, BUFLEN);
							copy(Out.begin(), Out.end(), buf);
							send(sockClient, buf, BUFLEN, 0);							
						}
				}

				
				if(a == 0){
					flag = false;
					break;	
				}
				flag = true;
			}
			flagnew = false;
			break;
		}
		
		if(flagnew == false)
			break;

	}
	close(sockClient);

}


int main(int argc, char const *argv[]){
	srand(time(NULL));
	char choice = '\0';
	cout << "Are you server?\nY or N\nInput H to !help\n";
	cin >> choice;
	if(choice == 'N' || choice == 'n')
		ClientStart();

	if(choice == 'Y' || choice == 'y')
		ServerStart();
		
	if(choice == 'h' || choice == 'h'){
		Help();
		cout << "Are you server?\nY or N\n Input H to !help\n";
		cin >> choice;
		if(choice == 'N' || choice == 'n')
			ClientStart();

		if(choice == 'Y' || choice == 'y')
			ServerStart();
	}
	return 0;
}
