#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std;
//Number of men and women
#define N  5                                                        

// This function returns true if woman 'w' prefers man 'm1' over man 'm'
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1) 
{ 
    // Check if w prefers m over her current engagement m1
    for (int i = 0; i < N; i++) 
    {  
        // If m1 comes before m in list of w
        // then w prefers her current engagemen, don't do anything
        if (prefer[w][i] == m1) 
            return true; 
        // If m comes before m1 in w's list
        // free her current engagement and engage her with m
        if (prefer[w][i] == m) 
            return false; 
    } 
} 

void stable(int prefer[2*N][N]) 
{ 

    int wPartner[N]; 

    bool mFree[N]; 

    memset(wPartner, -1, sizeof(wPartner)); 
    memset(mFree, false, sizeof(mFree)); 
    int freecount = N; 

    while (freecount > 0) 
    { 
        int m; 
        for (m = 0; m < N; m++) 
            if (mFree[m] == false) 
                break; 


        for (int i = 0; i < N && mFree[m] == false; i++) 
        { 
            int w = prefer[m][i]; 


            if (wPartner[w-N] == -1) 
            { 
                wPartner[w-N] = m; 
                mFree[m] = true; 
                freecount--; 
            } 

            else   
            { 
                int m1 = wPartner[w-N]; 


                if (wPrefersM1OverM(prefer, w, m, m1) == false) 
                { 
                    wPartner[w-N] = m; 
                    mFree[m] = true; 
                    mFree[m1] = false; 
                } 
            } 
        } 
    }  

    cout << "Women\t Men" << endl;

string wName;
string mName;
    for (int i = 0; i < N; i++){
    if(i < N){
    if(wPartner[i] == 0)
        mName = "Victor";
    if(wPartner[i] == 1)
        mName="Wyatt";
    if(wPartner[i] == 2)
        mName="Xavier";
    if(wPartner[i] == 3)
        mName="Yancey";
    if(wPartner[i] == 4)
        mName="Zeus";
    if(i==0)
        wName="Amy";
    if(i==1)
        wName="Bertha";
    if(i==2)
        wName="Clare";
    if(i==3)
        wName="Diane";
    if(i==4)
        wName="Erika";
    }
    cout << wName << "\t" << mName << endl;
}
}  
int main() 
{ 
    int prefer[2*N][N] = { 
        {6,5,8,9,7},
        {8,6,5,7,9},
        {6,9,7,8,5},
        {5,8,7,6,9},
        {6,8,5,9,7},
        {4,0,1,3,2},
        {2,1,3,0,4},
        {1,2,3,4,0},
        {0,4,3,2,1},
        {3,1,4,2,0} 
    }; 
    stable(prefer); 

    return 0; 
}