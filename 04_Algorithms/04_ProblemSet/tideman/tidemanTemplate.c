#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

typedef struct{
    string candidatefinal;
    bool qualified;
}checkSource;

checkSource people[MAX];

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }
        // for(int i=0;i<candidate_count;i++){

        //     printf("%d ",ranks[i]);
        // }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for(int i=0;i<candidate_count;i++){
        if(strcmp(name , candidates[i])==0){
            ranks[rank]= i;
            return true;
        }
    }

    
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    // printf("Hello world\n");
    for(int i =0;i<candidate_count;i++){
        // printf("check1 ");
        for(int j=i+1; j<candidate_count;j++){
            
                // if(!preferences[ranks[i]][ranks[j]]){
                //     preferences[ranks[i]][ranks[j]]=1;
                // }else
                // {
                    preferences[ranks[i]][ranks[j]]++;
                // }
                // printf("check2 ");

            // printf("%d-%d\n",ranks[i],ranks[j]);
        }
    }

    // for(int i=0;i<candidate_count;i++){
    //     for(int j=i+1;j<candidate_count;j++){

    //     printf("%d-%d=%d\n",ranks[i],ranks[j],preferences[ranks[i]][ranks[j]]);
    //     }
    // }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for(int i=0;i<candidate_count;i++){
            for(int j=0;j<candidate_count;j++){
                if(i!=j){
                    if(preferences[i][j]>preferences[j][i]){
                        pairs[pair_count].winner=i;
                        pairs[pair_count].loser=j;
                        pair_count++;
                    }
                    // else{
                    //     pairs[pair_count].winner=j;
                    //     pairs[pair_count].loser=i;
                    // }
            }
        }
    }
    // printf("\n%d\n",pair_count);
    // for(int i=0;i<pair_count;i++){
    //     printf("%s %d-%d %s\n",candidates[pairs[i].winner] ,pairs[i].winner,pairs[i].loser,candidates[pairs[i].loser]);
    // }
    // printf("%d-%d ",preferences[1][2],preferences[2][1]);
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            int strength1 = preferences[pairs[j].winner][pairs[j].loser];
            int strength2 = preferences[pairs[j + 1].winner][pairs[j + 1].loser];

            if (strength1 < strength2)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
}
bool cycle(int winner, int loser)
{
    // Base case: if there's a cycle back to the winner, return true
    if (winner == loser)
    {
        return true;
    }

    // Recursively check if any locked paths lead back to the winner
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (cycle(winner, i))
            {
                return true;
            }
        }
    }

    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
   

    for (int i = 0; i < pair_count; i++)
    {
        if (!cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}
  


// Print the winner of the election
void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool is_source = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                is_source = false;
                break;
            }
        }
        if (is_source)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}
