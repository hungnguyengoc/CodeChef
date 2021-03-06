#include <iostream>
using namespace std;

int main(){

    int numCases; scanf("%d\n",&numCases);
    while(numCases--){
        string message; getline(cin, message);
        size_t inputLength = message.size();
        bool *input   = new bool[inputLength];
        bool *attempt = new bool[inputLength];
        bool *output  = new bool[inputLength]; 

        for(size_t k = 0; k < inputLength; k++){input[k] = message[k] - '0';}
        int sol = 0; bool first = 0, second = 0;

        while(true){
            attempt[0] = first; attempt[1] = second;
            for(size_t n = 2; n < inputLength ; n++){attempt[n] = attempt[n-1] ^attempt[n-2] ^ input[n-1];}
            if(first ==(attempt[inputLength-1]^attempt[inputLength-2]^input[inputLength -1]) && second ==(attempt[0]^attempt[inputLength-1]^input[0])){
                sol++;
                for(size_t n = 0; n < inputLength ; n++){output[n] = attempt[n];}
            }
            
            first = first ^ second; second = !second;
            if(!first && !second){break;}
        }

        if (sol == 1){for(size_t k = 0; k < inputLength; k++){printf("%d", *(output+ k));};printf("\n");}
        else if(sol == 0){printf("No solution\n");}
        else if (sol > 1){printf("Multiple solutions\n");}
    }
    return 0;
}
