#include<iostream>
#include<string>
#include<math.h>
#include<cctype>
#include<windows.h>
#include <bitset>
using namespace std;
 string binaryToHex(string binaryString) {
    bitset<128> binary(binaryString);
    string hexString = "";
    int hexDigit;
    for (int i = 0; i < binaryString.length(); i += 4) {
        hexDigit = binary[i] * 8 + binary[i+1] * 4 + binary[i+2] * 2 + binary[i+3];
        if (hexDigit < 10) {
            hexString += to_string(hexDigit);
        } else {
            hexString += (char)(hexDigit - 10 + 'A');
        }
    }
    return hexString;
}
int bin_to_dec(string bin){	
	int dec=0,incr=0,sum=0;
	for(int i=(bin.length()-1);i>=0;i--){
		dec=bin[i]-'0';
		sum=sum+(int)(dec*(pow(2,incr)));
		incr++;
	}
	return sum;	
}

string dec_to_bin(int dec){
	int i=dec;
	string str="";
	char binary[4];
	while(1){
		int quotient=i/2;
		int remainder=i%2;
		i=quotient;
		itoa(remainder,binary,10);
		str=str+binary;
		if(quotient==0)break;
	}
	string fin_str="";
	for(int i=(str.length()-1);i>=0;i--){
		fin_str=fin_str+str[i];
	}
	return fin_str;
}

string process_string(string substring,int s[][4][16],int p){
	string row,col;
	for(int i=0;i<6;i++){
		if(i==0||i==5)row=row+substring[i];
		else{
			col=col+substring[i];
		}
	}
	int r=bin_to_dec(row);
	int c=bin_to_dec(col);
	int s_box_pos=s[p][r][c];
	string fbit_bin_str="0000";
	int len=dec_to_bin(s_box_pos).length();
	string bin=dec_to_bin(s_box_pos);

	for(int i=0;i<len;i++){
		fbit_bin_str[i+(4-len)]=bin[i];	
	}
	return fbit_bin_str;	
}

string fifty_six_bit_key(string key,int pc1[8][7]){
	int i,j,k,bin_key_index=0,index=0;
	string fs_bin_key;
	
	for(k=0;k<56;k++)fs_bin_key=fs_bin_key+'0';
	for(i=0;i<8;i++){
		for(j=0;j<7;j++){
			index=pc1[i][j]-1;
			fs_bin_key[bin_key_index]=key[index];
			bin_key_index++;		
		}
	}
	return fs_bin_key;
}

string rol_keys(string key,int rotating_schedule[16],int i){	
	int count=rotating_schedule[i],l,j,k;
	string rol_key;
	for(k=0;k<28;k++)rol_key=rol_key+'0';	
	while(count>0){
		for(l=0;l<28;l++){
			if(l==0)j=27;
			else{
				j=l-1;
			}
			rol_key[j]=key[l];
		}
		key=rol_key;
		count--;
	}	
	return rol_key;	
}

string fourty_eight_bit_key(string C,string D,int pc2[6][8]){		
	int fe_bin_key_index=0,concat_key_index=0,i,j,k;
	string fe_bin_key,concat_keys=C+D;
	for(i=0;i<48;i++)fe_bin_key=fe_bin_key+'0';
	for(i=0;i<6;i++){
		for(j=0;j<8;j++){
			concat_key_index=pc2[i][j]-1;
		  	fe_bin_key[fe_bin_key_index]=concat_keys[concat_key_index];
		  	fe_bin_key_index++;		
		}
	}	
	return fe_bin_key;
}

string initial_permuted_msg(string msg,int ip[8][8]){	
	int ip_msg_index=0,msg_index=0,i,j;
	string ip_msg;
	for(i=0;i<64;i++)ip_msg=ip_msg+'0';	
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			msg_index=ip[i][j]-1;
		  	ip_msg[ip_msg_index]=msg[msg_index];
		  	ip_msg_index++;		
		}
	}
	return ip_msg;
}

string expanded_msg(string R,int ep[8][6]){
	int ep_msg_index=0,R_index=0,i,j;
	string ep_msg;
	for(i=0;i<48;i++)ep_msg=ep_msg+'0';
	for(i=0;i<8;i++){
		for(j=0;j<6;j++){
			R_index=ep[i][j]-1;
			ep_msg[ep_msg_index]=R[R_index];
			ep_msg_index++;		
		}
	}
	return ep_msg;	
}

string xored_msg(string ep_msg,string fe_key){	
	int xor_val,i,len=ep_msg.length();
	char holder[len];
	string xored_msg;
	
	for(i=0;i<len;i++){
		xor_val=((fe_key[i]-'0')^(ep_msg[i]-'0'));
		itoa(xor_val,holder,10);
		xored_msg=xored_msg+holder;
	}	
	return xored_msg;	
}

string substitution_function(string xored_message,int sbox[][4][16]){
	string thirty_two_bit_msg;	
	int index=0,len=6;
	for(int i=0;i<48;i+=6){
		thirty_two_bit_msg=thirty_two_bit_msg+process_string(xored_message.substr(i,len),sbox,index);
		index++;	
	}
	return thirty_two_bit_msg;
}

string permuted_message(string thirty_two_bit_msg,int pf[4][8]){
	int index=0,thirty_two_bit_msg_index=0,i,j;
	string permuted_msg;
	for(i=0;i<thirty_two_bit_msg.length();i++)permuted_msg=permuted_msg+'0';
	for(i=0;i<4;i++){
		for(j=0;j<8;j++){
     	  		thirty_two_bit_msg_index=pf[i][j]-1;
		  	permuted_msg[index]=thirty_two_bit_msg[thirty_two_bit_msg_index];
		  	index++;	
		}
	}
	return permuted_msg;
}

string inverse_ip_msg(string reversed_msg,int inv_ip[8][8]){
	int inv_msg_index=0,index=0,i,j;
	string inv_msg="";
	for(i=0;i<64;i++)inv_msg=inv_msg+'0';
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
			index=inv_ip[i][j]-1;
		  	inv_msg[inv_msg_index]=reversed_msg[index];
		  	inv_msg_index++;	
		}
	}
	return inv_msg;
}

string hex_conversion(string de_msg,string conv_table[23],string hex[23]){
	int len=4;
	string substring="",hex_message="";		
	for(int i=0;i<64;i+=4){
		int find=0;
		substring=de_msg.substr(i,len);
		while(1){		
			if(conv_table[find]==substring)break;	
			find++;	
		}
		hex_message=hex_message+hex[find];
	}
	return hex_message;	
}

string des_process(string message,string key,bool encrypt){
	string conv_table[23]={
   		"0000",
	    	"0001",
   		"0010",
   		"0011",
   		"0100",
   		"0101",
   		"0110",
   		"0111",
   		"1000",
   		"1001",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
	    	"1010",
   		"1011",
   		"1100",
   		"1101",
   		"1110",
   		"1111"	
   };
   
   string hex[23]={
   		"0",
   		"1",
   		"2",
   		"3",
   		"4",
   		"5",
   		"6",
   		"7",
   		"8",
   		"9",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"pad",
   		"A",
   		"B",
   		"C",
   		"D",
   		"E",
   		"F"   	
   };
   
   int ip[8][8]={
		58, 50, 42, 34, 26, 18, 10, 2,
		60, 52, 44, 36, 28, 20, 12, 4,
		62, 54, 46, 38, 30, 22, 14, 6,
		64, 56, 48, 40, 32, 24, 16, 8,
		57, 49, 41, 33, 25, 17, 9,  1,
		59, 51, 43, 35, 27, 19, 11, 3,
		61, 53, 45, 37, 29, 21, 13, 5,
		63, 55, 47, 39, 31, 23, 15, 7	
   };
   
   int inv_ip[8][8]={   					
		40, 8, 48, 16, 56, 24, 64, 32,
		39, 7, 47, 15, 55, 23, 63, 31,
		38, 6, 46, 14, 54, 22, 62, 30,
		37, 5, 45, 13, 53, 21, 61, 29,
		36, 4, 44, 12, 52, 20, 60, 28,
		35, 3, 43, 11, 51, 19, 59, 27,
		34, 2, 42, 10, 50, 18, 58, 26,
		33, 1, 41, 9,  49, 17, 57, 25	
   };
   
   int ep[8][6]={
		32, 1, 2, 3, 4, 5,
		4,  5, 6, 7, 8, 9,
		8,  9, 10, 11, 12, 13,
		12, 13, 14, 15, 16, 17,
		16, 17, 18, 19, 20, 21,
		20, 21, 22, 23, 24, 25,
		24, 25, 26, 27, 28, 29,
		28, 29, 30, 31, 32, 1
   };
   
   int pf[4][8]={					
		16, 7, 20, 21, 29, 12, 28, 17,
		1, 15, 23, 26, 5,  18, 31, 10,
		2, 8,  24, 14, 32, 27, 3,  9,
		19,13, 30, 6,  22, 11, 4,  25
   };
   
   int sbox[8][4][16]={
   	{
		14, 4, 13, 1, 2, 15, 11, 8, 3,  10, 6,  12, 5, 9,  0, 7,
	     	0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12,  11, 9, 5,  3, 8,
		 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9,   7, 3, 10, 5, 0,
		15, 12, 8, 2,  4, 9, 1,  7, 5,  11, 3,  14, 10, 0, 6, 13
    	},
	{
		15, 1, 8, 14, 6, 11, 3,  4,  9,  7, 2, 13, 12,  0, 5, 10,
            	3, 13, 4, 7,  15, 2, 8, 14, 12,  0, 1, 10,  6,  9, 11, 5,
            	0, 14, 7, 11, 10, 4, 13, 1,  5,  8, 12, 6,  9,  3,  2, 15,
            	13, 8, 10, 1, 3, 15, 4,  2, 11,  6, 7, 12,  0,  5, 14,  9
	},
	{
		10, 0, 9, 14, 6, 3, 15, 5,  1, 13, 12, 7, 11, 4,  2,  8,
		13, 7, 0, 9,  3, 4,  6, 10, 2, 8,  5, 14, 12, 11, 15, 1,
		13, 6, 4, 9,  8, 15, 3, 0, 11, 1,  2, 12, 5,  10, 14, 7,
		1, 10, 13, 0, 6, 9,  8, 7,  4, 15, 14, 3, 11, 5,  2, 12
	},
	{
		7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
	    	13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
		10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
		3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14,
	},
	{
		2,  12, 4, 1,  7, 10, 11, 6, 8, 5, 3,  15, 13, 0, 14, 9,
		14, 11, 2, 12, 4, 7,  13, 1, 5, 0, 15, 10, 3,  9, 8,  6,
		4,  2,  1, 11, 10,13, 7,  8, 15,9, 12, 5,  6,  3, 0,  14,
		11, 8, 12, 7,  1, 14, 2, 13, 6, 15, 0, 9,  10, 4, 5,  3
	},
	{
	    	12, 1, 10, 15,9, 2, 6, 8, 0, 13, 3, 4, 14, 7,  5, 11,
		10, 15, 4, 2, 7, 12,9, 5, 6, 1, 13, 14, 0, 11, 3,  8,
		9,  14,15, 5, 2, 8, 12,3, 7, 0, 4,  10, 1, 13, 11, 6,
		4,  3,  2, 12,9, 5, 15,10,11,14,1,  7,  6, 0,  8, 13
	},
	{
	    	4, 11, 2,  14, 15, 0, 8, 13, 3,  12, 9, 7,  5, 10, 6, 1,
	       	13, 0,  11, 7,  4,  9, 1, 10, 14,  3, 5, 12, 2, 15, 8, 6,
		1, 4,  11, 13, 12, 3, 7, 14, 10, 15, 6,  8, 0,  5, 9, 2,
		6, 11, 13, 8,  1,  4, 10, 7, 9,  5,  0, 15, 14, 2, 3, 12
	},
	{
	 	13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3,  14, 5, 0, 12, 7,
		 1, 15,13, 8, 10, 3, 7,  4, 12, 5, 6,  11, 0, 14, 9, 2,
	     	7, 11, 4, 1, 9, 12, 14, 2,  0, 6, 10, 13, 15, 3, 5, 8,
	     	2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9,  0, 3,  5, 6, 11
	}
   };
  
  int pc1[8][7]={
	57, 49, 41, 33, 25, 17, 9,
	1,  58, 50, 42, 34, 26, 18,
	 10, 2,  59, 51, 43, 35, 27,
    	19, 11, 3,  60, 52, 44, 36,
    	63, 55, 47, 39, 31, 23, 15,
    	7,  62, 54, 46, 38, 30, 22,
    	14, 6,  61, 53, 45, 37, 29,
    	21, 13, 5,  28, 20, 12, 4
  };
 
  int pc2[6][8]={
	14, 17, 11, 24, 1,  5,  3, 28,
	15, 6,  21, 10, 23, 19, 12, 4,
	26, 8,  16, 7,  27, 20, 13, 2,
	41, 52, 31, 37, 47, 55, 30, 40,
	51, 45, 33, 48, 44, 49, 39, 56,
	34, 53, 46, 42, 50, 36, 29, 32
  };

  int rotating_schedule[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    /*necessary tables initialization ends*/
    /*hexadecimal msg and key input and conversion to binary starts*/
  string bin_key,input; 
  cout<<"Input hex message:";
  for(int i=0;i<16;i++){
  	cout<<message[i];
  } 
  for(int i=0;i<16;i++){
 	int a=message[i]-'0';
 	input=input+conv_table[a];
  }
  cout<<endl;
  cout<<"Output Binary Message:\n"<<input<<endl;

  for(int i=0;i<16;i++){
	int a=key[i]-'0';
	bin_key=bin_key+conv_table[a];
  }
  cout<<"Output Binary key:\n"<<bin_key<<endl;
  /*hexadecimal msg and key input and conversion to binary ends*/
	
   	/*Key processing starts*/

  string fs_key=fifty_six_bit_key(bin_key,pc1);
  cout<<"Fifty Six Bit Key:\n"<<fs_key<<endl;

  string ip_msg=initial_permuted_msg(input,ip);
  cout<<"IP message:\n"<<ip_msg<<endl;

  string Lo=ip_msg.substr(0,32);
  cout<<"\nL["<<0<<"]:"<<Lo<<endl;

  string Ro=ip_msg.substr(32,64);
  cout<<"R["<<0<<"]:"<<Ro<<endl;

  string Co=fs_key.substr(0,28);
  //cout<<"\nC["<<0<<"]:"<<Co<<endl;/*If you want to see the left half of the key*/

  string Do=fs_key.substr(28,56);
  //cout<<"D["<<0<<"]:"<<Do<<endl;/*If you want to see the right half of the key*/

  int round=16;
  string key_holder[round],fe_key;
  for(int i=0;i<round;i++){
  	int iteration=i;
  	string C1=rol_keys(Co,rotating_schedule,iteration%round);
   	string D1=rol_keys(Do,rotating_schedule,iteration%round);   
   
   	fe_key=fourty_eight_bit_key(C1,D1,pc2);
   	key_holder[i]=fe_key;
	      		
        Co=C1;
   	Do=D1;		   /*key processing ends*/
   }

   int i=0;      
   while(round>0){
   	cout<<"\nRound:"<<i+1<<endl;
    	Sleep(500);
	
    	string ep_msg=expanded_msg(Ro,ep);
    	cout<<"Expanded msg(ER["<<i<<"]):\n"<<ep_msg<<endl;  
	
    	if(encrypt==false){
    		fe_key="";
    		for(int j=0;j<48;j++)fe_key=fe_key+key_holder[round-1][j];
    		cout<<"\nkey["<<round<<"]:\n"<<fe_key<<endl;
      	}
      	else{
      		fe_key="";
		for(int j=0;j<48;j++)fe_key=fe_key+key_holder[i][j];
	    	cout<<"\nkey["<<i+1<<"]:\n"<<fe_key<<endl;
    	}
      
	string xored_message=xored_msg(ep_msg,fe_key);
    	cout<<"Xored Message(E(R["<<i<<"]+K["<<i+1<<"]):\n"<<xored_message<<endl;
    
    	string substituted_msg=substitution_function(xored_message,sbox);
    	cout<<"Substituted Message(S-Box outputs):\n"<<substituted_msg<<endl;
    
    	string permuted_msg=permuted_message(substituted_msg,pf);
    	cout<<"Permuted message(f(R["<<i<<"],K["<<i+1<<"])):\n"<<permuted_msg<<endl;
   
    	string L1=Ro;
        string str_l1 = binaryToHex(L1);
    	cout<<"L["<<i+1<<"]:"<<str_l1<<endl;
	
    	string R1=xored_msg(Lo,permuted_msg);
          string str_r1 = binaryToHex(R1);
    	cout<<"R["<<i+1<<"]:"<<str_r1<<endl;
    
    	Lo=L1;
    	Ro=R1;

    	round--;
    	i++;	    	    
     }

     string reversed_msg=Ro+Lo;
     cout<<"\nReversed message:\n"<<reversed_msg<<endl;

     string des_encrypted_msg=inverse_ip_msg(reversed_msg,inv_ip);
     cout<<"DES Encrypted Binary Message:\n"<<des_encrypted_msg<<endl;

     string hex_encrypted_msg=hex_conversion(des_encrypted_msg,conv_table,hex);

     return hex_encrypted_msg;
	
}

bool input_verifier(string message){
	 int count=0,found=0;
	 string hex_standard="0123456789ABCDEF";
	 
	 for(int i=0;i<message.length();i++){
	 	for(int j=0;j<hex_standard.length();j++){
  	    		if(message[i]==hex_standard[j])count++;	
  	    } 	
	 }
	 
	 if(count==message.length())found=1;	
	 if(message.length()>16||message.length()<16||found==0){ 
	 	return false;
	 }
	 else{
		return true;
	 }
}
			
int main(){
	cout<<"Do you want to put a Hex Message by your own?(y/n):";
	string message,key;
	char ch,endc;
	bool encrypt;
	cin>>ch;
	if(tolower(ch)=='y'){
		 while(1){
			 cout<<"Enter the hex message(all upper case,type quit to quit):";
			 cin>>message;
			 bool check=input_verifier(message);
			 if(check==true||message=="quit")break;
			 else{
			 	cout<<"Wrong Input!"<<endl;
			 }
	 	 }
	 	 while(1){
			 cout<<"Enter the hex key(all upper case,type quit to quit):";
			 cin>>key;
			 bool check=input_verifier(key);
			 if(check==true||key=="quit")break;
			 else{
			 	cout<<"Wrong Input!"<<endl;	
			 }
 	 	 }
 	 	 
 	 	 if(message=="quit"&&key=="quit"){   		
   			cout<<"Now program will run on hard coded hex message:0123456789ABCDEF \nand key:133457799BBCDFF1"<<endl;
			Sleep(1000);
			string message="0123456789ABCDEF",key="133457799BBCDFF1";	
			string encrypted_msg=des_process(message,key,true);
		    	cout<<"Finally!!Hex Encrypted Message:"<<encrypted_msg<<endl;
	
			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string decrypted_msg=des_process(encrypted_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
			}
		  }
	 	  else{
			 cout<<"Encrypt/Decrypt(e/d)?:";
		 	 cin>>endc;
		 	 if(tolower(endc)=='e')encrypt=true;
		 	 else encrypt=false;
	  		 
		 	if(message!="quit" && key!="quit"){
		 		if(encrypt){	
		 	 		string encrypted_msg=des_process(message,key,encrypt);
		 	 		cout<<"\nFinally!!DES Encrypted Hex Message:"<<encrypted_msg<<endl;
		 	 		cout<<"Do you want to see its decryption(y/n):";
		 	 		char input;
		 	 		cin>>input;
		 	 		if(tolower(input)=='y'){
	 	 				string decrypted_msg=des_process(encrypted_msg,key,false);
		 	 			cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
		 	 	}
		  	}
	 	  	else{	 	
	   			string decrypted_msg=des_process(message,key,encrypt);
	  	 		cout<<"\nFinally!!DES Decrypted Hex Message:"<<decrypted_msg<<endl;  	 	
	  	 	}
	 	  }
	   	  else if(message=="quit"){
	    	   	cout<<"Now program will run on hard coded hex message:0123456789ABCDEF"<<endl;
		   	Sleep(1000);
			string message="0123456789ABCDEF";	
			string encrypted_msg=des_process(message,key,encrypt);
		    	cout<<"Finally!!Hex Encrypted Message:"<<encrypted_msg<<endl;
		
			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string decrypted_msg=des_process(encrypted_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
			}	
	   	  }
	    	  else if(key=="quit"){
	    		cout<<"Now program will run on hard coded hex key:133457799BBCDFF1"<<endl;
			Sleep(1000);
			string key="133457799BBCDFF1";	
			string encrypted_msg=des_process(message,key,encrypt);
		        cout<<"Finally!!DES Encrypted Hex Message:"<<encrypted_msg<<endl;
	
			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string decrypted_msg=des_process(encrypted_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
			}
		   }	   	
	       }
	}
	else{		
	 	string ascii_table[26]={			   	
	   		"61",
			"62",
			"63",
			"64",
			"65",
			"66",
			"67",
			"68",
			"69",
			"6A",
			"6B",
			"6C",
			"6D",
			"6E",
			"6F",
			"70",
			"71",
			"72",
			"73",
			"74",
			"75",
			"76",
			"77",
			"78",
			"79",
			"7A"
							  	
		};
   		string characters="abcdefghijklmnopqrstuvwxyz";	
		cout<<"Do you want to put plaintext?(y/n):";
		char inp;
		cin>>inp;
		if(tolower(inp)=='y'){
			string str="",message="";
			cout<<"Type the plain text 8 characters long(a to z):";
			cin>>str;
			
			for(int i=0;i<str.length();i++){
				int find=0;
				while(1){
					if(str[i]==characters[find])break;
					find++;
				}
				message=message+ascii_table[find];
			}
			
			while(1){
				 cout<<"Enter the hex key(all upper case,type quit to quit):";
				 cin>>key;
				 bool check=input_verifier(key);
				 if(check==true)break;
				 else{
				 	cout<<"Wrong Input!"<<endl;	 	
				 }
 	 	 	}
			string enc_msg=des_process(message,key,true);
	    		cout<<"Finally!!Hex Encrypted Message:"<<enc_msg<<endl;

			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string de_msg=des_process(enc_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<de_msg;
				
				int len=2;
				string substring="",plain_txt="";		
				for(int i=0;i<16;i+=2){
					int find=0;
					substring=de_msg.substr(i,len);
					while(1){
						if(ascii_table[find]==substring)break;	
						find++;	
					}
					plain_txt=plain_txt+characters[find];
		        	}
				cout<<"\nDecrypted plain text is:"<<plain_txt<<endl;
			}
   
		}
		else{
			cout<<"Now program will run on hard coded hex message:0123456789ABCDEF \nand key:133457799BBCDFF1"<<endl;
			Sleep(1000);
			string message="0123456789ABCDEF",key="133457799BBCDFF1";	
			string encrypted_msg=des_process(message,key,true);
			cout<<"Finally!!Hex Encrypted Message:"<<encrypted_msg<<endl;
			
			char ch;
			cout<<"Want to see decryption?(y/n):";
			cin>>ch;
			if(tolower(ch)=='y'){
				cout<<"Decrytion Starts:"<<endl;
				string decrypted_msg=des_process(encrypted_msg,key,false);
				cout<<"Finally!!DES Decrypted Hex Message:"<<decrypted_msg;
			}	
		}				
	}
 	return 0;
}
	