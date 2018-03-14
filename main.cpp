//
//  main.cpp
//  LargeIntMul
//
//  Created by shijia hu on 3/18/17.
//  Copyright © 2017 shijia hu. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int charToInt(char c){
    return c - '0';
}

char intToChar(int n){
    return n + '0' ;
}

string reverseStr(string input){
    
    string output = "";
    for(int i = 0; i < input.length(); i++){
        output.insert(output.begin(),input[i]);
    }
    return output;
    
}
int countDigit(long int num){
    int count = 0;
    while (num != 0)
    {
        count++;
        num = num/10;
    }
    return count;
}

string addZero(string a, int n){
    for (int i = 0; i<n; i++) {
        a = a +'0';
    }
    return a;
}

string deleteZero(string s)
{
    int p,i;
    p=0;
    i=0;
    while(charToInt(s[i])==0) i++;
    string s2 = s.substr(i,s.length());

    return s2;

}

string sumofStr(string _s1, string _s2){
    string s1 = reverseStr(_s1);
    string s2 = reverseStr(_s2);
    int pMax = s1.length() > s2.length() ? s2.length() : s1.length();
    string sumStr = "";
    int p;
    int carry = 0;
    int temp = 0;
    for(p = 0; p < pMax; p++){
        temp = charToInt(s1[p]) + charToInt(s2[p]) + carry;
        carry = temp / 10;
        sumStr.insert(sumStr.begin(),intToChar(temp % 10));
    }
    if(p < s1.length()){
        for(; p < s1.length(); p++){
            temp = charToInt(s1[p]) + carry;
            carry = temp / 10;
            sumStr.insert(sumStr.begin(),intToChar(temp % 10));
        }
    }
    if(p < s2.length()){
        for(; p < s2.length(); p++){
            temp = charToInt(s2[p]) + carry;
            carry = temp / 10;
            sumStr.insert(sumStr.begin(),intToChar(temp % 10));
        }
    }
    if(carry > 0){
        sumStr.insert(sumStr.begin(),intToChar(carry % 10));
        carry /= 10;
    }
    return sumStr;
    
}



//long int LargeIntegerMul(long int u, long int v){
//    long int x,y,z,a,b,c,temp1,temp2;
//    int n,m;
//    n = max(countDigit(u),countDigit(v));
//    if (u == 0 || v == 0) {
//        return 0;
//    }else if (n <= 6 ){
//        return u*v;
//    }else{
//        m = n/3;
//        x = u / pow(10, 2*m);
//        temp1 = u / pow(10, m);
//        y = temp1 % (long int)pow(10, m);
//        z = u % (long int)pow(10, m);
//        
//        a = v / pow(10, 2*m);
//        temp2 = v / pow(10, m);
//        b = temp2 % (long int)pow(10, m);
//        c = v % (long int)pow(10, m);
//        return LargeIntegerMul(x, a) * pow(10, 4*m) + (LargeIntegerMul(x, b) + LargeIntegerMul(y, a)) * pow(10, 3*m) + (LargeIntegerMul(x, c) + LargeIntegerMul(y, b) + LargeIntegerMul(z, a)) * pow(10, 2*m) + (LargeIntegerMul(y, c) + LargeIntegerMul(z, b)) * pow(10, m) + LargeIntegerMul(z, c);
//    }

//}

char *LargeIntegerMulInClass(char *u, char *v){
    char *x,*y,*z,*w,*temp1,*temp;
    
    temp = new char [20];
    int n,m,count,i;
    n = max(strlen(u),strlen(v));
    if ( n <= 3 ){
        
        int tempint;
        tempint = atoi(u)*atoi(v);
        sprintf(temp,"%d",tempint);
        
        return temp;
    }else{
        int abc = n/2;
        m = n - n/2;
        x = new char [m+1];
        y = new char [m+1];
        z = new char [m+1];
        w = new char [m+1];
        
        string str1 = string(u);
        string str2 = string(v);

        if (abc < m) {
            str1 = '0' + str1;
            str2 = '0' + str2;
        }else{
            ;
            
        }


        string x1 = str1.substr(0,m);
        strcpy(x, x1.c_str()) ;
        string y1 = str1.substr(m,m);
        strcpy(y, y1.c_str()) ;
        string w1 = str2.substr(0,m);
        strcpy(w, w1.c_str()) ;
        string z1 = str2.substr(m,m);
        strcpy(z, z1.c_str()) ;

        string str7 = string(LargeIntegerMulInClass(x, w));
        string str8 = string(LargeIntegerMulInClass(x, z));
        string str9 = string(LargeIntegerMulInClass(w, y));
        string str10 = string(LargeIntegerMulInClass(y, z));//yz

        string strtemp1 = addZero(str7, 2*m);//xw*10^2m
        string strtemp2 = sumofStr(str8, str9);
        string strtemp3 = addZero(strtemp2, m);//xz+wy  * 10^m
        string strtemp4 = sumofStr(strtemp1, strtemp3);
        string strtemp5 = sumofStr(strtemp4, str10);
        
        string sss = deleteZero(strtemp5);
        count = sss.length();
        temp1 = new char [count+1];
        strcpy(temp1, sss.c_str());

        return temp1;
    }
}


char *LargeIntegerMul(char *u, char *v){
    char *x,*y,*z,*a,*b,*c,*temp1,*temp;
    
    temp = new char [20];
    int n,m,count;
    n = max(strlen(u),strlen(v));
     if (n <= 3 ){
        int tempint;
        tempint = atoi(u)*atoi(v);
        sprintf(temp,"%d",tempint);
        
        return temp;
    }else{

        int abc = n/3;
        int ddd = n - abc -abc;
        if(ddd > abc) m = abc + 1;
        else m = abc;
        string str1 = string(u);
        string str2 = string(v);

        x = new char [m+1];
        y = new char [m+1];
        z = new char [m+1];
        a = new char [m+1];
        b = new char [m+1];
        c = new char [m+1];

        if(abc == ddd -1)
        {
            str1 = '0' + str1;
            str2 = '0' + str2;
            str1 = '0' + str1;
            str2 = '0' + str2;
        }
        else if(abc == ddd - 2)
        {
            str1 = '0' + str1;
            str2 = '0' + str2;
        }
        else{

        }

        //string str1 = string(u);
        string x1 = str1.substr(0,m);
        strcpy(x, x1.c_str()) ;
        //string str2 = string(u);
        string y1 = str1.substr(m,m);
        strcpy(y, y1.c_str()) ;
        //string str3 = string(u);
        string z1 = str1.substr(2*m,m);
        strcpy(z, z1.c_str()) ;
        
        //string str4 = string(v);
        string a1 = str2.substr(0,m);
        strcpy(a, a1.c_str()) ;
        //string str5 = string(v);
        string b1 = str2.substr(m,m);
        strcpy(b, b1.c_str()) ;
        //string str6 = string(v);
        string c1 = str2.substr(2*m,m);
        strcpy(c, c1.c_str()) ;

        string str7 = string(LargeIntegerMul(x, a));
        string str8 = string(LargeIntegerMul(x, b));
        string str9 = string(LargeIntegerMul(x, c));
        string str10 = string(LargeIntegerMul(y, a));
        string str11 = string(LargeIntegerMul(y, b));
        string str12 = string(LargeIntegerMul(y, c));
        string str13 = string(LargeIntegerMul(z, a));
        string str14 = string(LargeIntegerMul(z, b));
        string str15 = string(LargeIntegerMul(z, c));//LargeIntegerMul(z, c);

        
        string strtemp1 = addZero(str7, 4*m);//LargeIntegerMul(x, a) * pow(10, 4*m)
        string strtemp2 = sumofStr(str8,str10);
        string strtemp3 = addZero(strtemp2, 3*m);//(LargeIntegerMul(x, b) + LargeIntegerMul(y, a)) * pow(10, 3*m)
        string strtemp4 = sumofStr(str9, str11);
        string strtemp5 = sumofStr(strtemp4, str13);
        string strtemp6 = addZero(strtemp5, 2*m);//(LargeIntegerMul(x, c) + LargeIntegerMul(y, b) + LargeIntegerMul(z, a)) * pow(10, 2*m)
        string strtemp7 = sumofStr(str12, str14);
        string strtemp8 = addZero(strtemp7, m);//(LargeIntegerMul(y, c) + LargeIntegerMul(z, b)) * pow(10, m)
        string strtemp9 = sumofStr(strtemp1, strtemp3);
        string strtemp10 = sumofStr(strtemp9, strtemp6);
        string strtemp11 = sumofStr(strtemp10, strtemp8);
        string strtemp12 = sumofStr(strtemp11, str15);
        
        //return LargeIntegerMul(x, a) * pow(10, 4*m) + (LargeIntegerMul(x, b) + LargeIntegerMul(y, a)) * pow(10, 3*m) + (LargeIntegerMul(x, c) + LargeIntegerMul(y, b) + LargeIntegerMul(z, a)) * pow(10, 2*m) + (LargeIntegerMul(y, c) + LargeIntegerMul(z, b)) * pow(10, m) + LargeIntegerMul(z, c);
        string sss = deleteZero(strtemp12);
        count = sss.length();
        temp1 = new char [count+1];
        strcpy(temp1, sss.c_str());
        return temp1;

    }
}


int main(int argc, const char * argv[]) {
    srand(time(0));
    int i;
    cout<<"Please enter n(=6k where k is a positive integer):"<<endl;
    int n;
    cin>>n;

    char *arr1,*arr2;
    arr1 = new char [n+1];
    arr2 = new char [n+1];

    for(i=0;i<n;i++)
    {
        arr1[i] = '0';
        arr2[i] = '0';
    }

    arr1[i] = 0;
    arr2[i] = 0;
    
    while ( arr1[0] == '0') {
           arr1[0] = rand() % 10 + '0';
    }
    while ( arr2[0] == '0') {
        arr2[0] = rand() % 10 + '0';
    }

    for (i = 1; i<n; i++) {
        arr1[i] = rand() % 10 + '0';
        arr2[i] = rand() % 10 + '0';
    }

    cout<<"u = "<<arr1<<endl;
    cout<<"v = "<<arr2<<endl;

    cout<<"The result is:(n/3)"<<endl;
    cout<<LargeIntegerMul(arr1, arr2)<<endl;
    cout<<"The result is:(n/2 in class)"<<endl;
    cout<<LargeIntegerMulInClass(arr1, arr2)<<endl;
    
    delete [] arr1;
    delete [] arr2;

    return 0;
}








