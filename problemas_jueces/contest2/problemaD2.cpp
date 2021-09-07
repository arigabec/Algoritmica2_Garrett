#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const int MaxIndex = 31268;
int lengthBefore[MaxIndex + 5];
int lengthOf[MaxIndex + 5];

int getNumDigits(ull currentHighest){
    int numDigits = 0;
    while (currentHighest){
        numDigits++;
        currentHighest /= 10;
    }
    return numDigits;
}

void GenerateData(){
    int i = 1, totalLength = 0, currentLength = 1;
    while (i < MaxIndex){
        totalLength += currentLength;
        lengthBefore[i] = totalLength;
        lengthOf[i] = currentLength;
        i++;
        currentLength += getNumDigits(i);
    }
}

int GetNumber(int position){
    int * nextOne = lower_bound(lengthBefore, lengthBefore + MaxIndex, position);
    position -= *(nextOne - 1);
    int * numberLengthOf = lower_bound(lengthOf, lengthOf + MaxIndex, position);
    int numberPartOf = numberLengthOf - lengthOf;
    int totalDigits = getNumDigits(numberPartOf);
    int positionInNumberFromFront = position - *(numberLengthOf - 1);
    int digitsToRemove = totalDigits - positionInNumberFromFront;
    while (digitsToRemove){
        numberPartOf /= 10;
        digitsToRemove--;
    }
    return numberPartOf % 10;
}

int main(){
    GenerateData();
    int cases;
    cin >> cases;
    while (cases--){
        int pos;
        cin >> pos;
        cout << GetNumber(pos) << endl;
    }
}