#include <stdio.h>
#include <cs50.h>

typedef struct 
{
   string name;
   int votes;
}candidate;

int main(){

    const int num_candidates = 3;
    candidate candidates[num_candidates];

    candidates[0].name = "Carter";
    candidates[0].votes = 10;

    candidates[1].name = "Yuliia";
    candidates[1].votes = 12;

    candidates[2].name = "Inno";
    candidates[2].votes = 7;


    // Todo : find hightest number of votes 
    // using linear search
    int highestVotes = candidates[0].votes;
    int candidateindex = 0;
    for(int i = 1;i<num_candidates;i++){
        if(candidates[i].votes>highestVotes){
            highestVotes =candidates[i].votes;
            candidateindex =i;
        }
            
        };
    // Todo : print name of candidae with higest number of votes ;
        printf("%d , %s", highestVotes , candidates[candidateindex].name);
    

    return 0;
}