#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

#define numofchars 256

int search(char pat[], char txt[], int primeNumber){
    int patternLen = strlen(pat);
	int textLen = strlen(txt);
	int i,j;
	int patternHash = 0; // hash value for pattern
	int textHash = 0; // hash value for txt
    int h = 1;
    int lastIndex=0;
    int res=0;
    //Hash First pattern and text (execute only once)

    for(i = 0; i < patternLen-1; i++){
        h = (h*numofchars)%primeNumber;
    }

    for (i = 0; i < patternLen; i++){
        if(pat[i]!='.'){
            patternHash = (numofchars*patternHash + pat[i])%primeNumber;
            textHash = (numofchars*textHash + txt[i])%primeNumber;
        }else{
            lastIndex=i;
            break;
        }
	}
	cout<< "Pattern hash: "<<patternHash <<endl;
    cout<< "Text hash: "<<textHash <<endl;
    for (i = 0; i <= textLen - patternLen; i++){
        if(patternHash==textHash){
            for (j = 0; j < patternLen; j++){
                if (txt[i+j] != pat[j]){
                    break;
                }
            }
            if (j == patternLen){
                    res++;
            }
        }


    }






    return res;


}


int main(){

    char txt[] = "hello there im working on a plagiarism checker for bulacan state university.and im also working on a grammar checker. written in c++ for better speed.hello there im working on a plagiarism checker for bulacan state university.";
	char pat[] = "hello there im working on a plagiarism checker for bulacan state university.";
	int q = 101; // A prime number
	int res = search(pat, txt, q);
	cout << res;
	return 0;
}

