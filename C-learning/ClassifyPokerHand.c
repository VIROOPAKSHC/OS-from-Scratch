/*
Author: Viroopaksh Chekuri
Purpose: Classify a given poker hand of 5 cards, into one of the many categories.
*/
#include<stdio.h>
#include<stdbool.h> // Enables boolean usage.

#define max(a,b) ((a>b)?(a):(b))
char face[] = {
    '2','3','4','5','6','7','8','9','T','K','Q','J', 'A'
}; // face value of the cards possible

char suits[] = {'c','s','h','d'}; // each character represents:
// c - clubs
// s - spades
// h - hearts
// d - diamonds

char* possible_hands[]={
    "straight Hush ( both a straight and a flush )",
    "four-of-a-kind (four cards of the same rank )",
    "full house (a three-of-a-kind and a pair)",
    "flush (five cards of the same suit )",
    "straight ( five cards with consecutive ranks )",
    "three-of-a-kind ( three cards of the same rank )",
    "two pairs",
    "pair ( two cards of the same rank )",
    "high card (any other hand )"
};

void classifyHand(int hand[][2]){
    int faceHashTbl[13] = {0};
    int i=0;
    int maxFaceNum = 0;
    int maxSuitNum = 0;
    for(i=0;i<5;i++){
        faceHashTbl[hand[i][0]]++;
    }
    
    int faceFreq[5] = {0};
    for(i=0;i<13;i++){
        faceFreq[faceHashTbl[i]]++;
    }
    int suitHashTbl[4] = {0};
    for(i=0;i<5;i++){
        suitHashTbl[hand[i][1]]++;
        maxSuitNum = max(maxSuitNum,suitHashTbl[hand[i][1]]);
    }
    int suitFreq[6] = {0};
    for(i=0;i<4;i++){
        suitFreq[suitHashTbl[i]]++;
    }
    bool flush = false;
    
    if(faceFreq[4] == 1){
        printf("You got a four-of-a-kind (four cards of the same rank )\n");
        return;
    }
    if(suitFreq[5] == 1){
        flush = true;
    }
    int j = 0;
    while(faceHashTbl[j]==0){
        j++;
    }
    bool straight = true;
    int count = 5;
    for(;(j<13 && count>0);j++){
        if(faceHashTbl[j]==0){
            straight=false;
            break;
        }
        count--;
    }

    if(straight==true){
        if(flush==true){
            printf("You got a straight Hush ( both a straight and a flush )\n");
        }
        else{
            printf("You got a straight ( five cards with consecutive ranks )\n");
        }
        return;
    }
    else if(flush==true){
        printf("You got a flush (five cards of the same suit )\n");
        return;
    }

    if(faceFreq[2]==2){
        printf("You got a two pairs\n");
        return;
    }
    else if (faceFreq[2]==1){
        if(faceFreq[3]==1){
            printf("You got a full house (a three-of-a-kind and a pair)\n");
            return;
        }
        else{
            printf("You got a pair ( two cards of the same rank )\n");
            return;
        }
    }
    else if(faceFreq[3]==1){
        printf("You got a three-of-a-kind ( three cards of the same rank )\n");
        return;
    }

    printf("You got a high card (any other hand )\n");
    // printf("\n");
    return;
}

int validateCard(char b, int flag){

    // TODO: ADD A RULE TO CHECK IF THE CARD HAS ALREADY BEEN RECORDED!!!!!
    if(flag==0){
        /*Validate face value */
        int i=0;
        for(i=0;i<13;i++){
            if(face[i]==b){
                return i;
            }
            else if((i>=8) && (face[i]+32==b)){
                return i;
            }
        }
    }
    else{
        /*Validate suit*/
        int i=0;
        for(i=0;i<4;i++){
            if(suits[i]==b){
                return i;
            }
            else if(suits[i]+32==b){
                return i;
            }
        }
    }
    return -1;
}



int main(void){
    // Input of 5 cards
    int hand[5][2];
    int i=0;
    printf("Enter the hand: ");
    for(i=0;i<5;i++){
        
        fflush(stdout);
        char faceChar;
        int valueidx;
        /* read a non-whitespace face char and validate */
        do{
            do{
                faceChar = getchar();
            }while(faceChar == '\n' || faceChar == ' ' || faceChar == '\t');
            // printf("THIS IS WHAT I GOT: %c\n", faceChar);
            valueidx = validateCard(faceChar, 0);
            if(valueidx == -1){
                printf("Wrong face value, retry in the possible values.\n");
                printf("Enter card: ");
            } else {
                hand[i][0] = valueidx;
            }
        }while(valueidx == -1);

        char suitChar;
        /* read a non-whitespace suit char and validate */
        do{
            do{
                suitChar = getchar();
            }while(suitChar == '\n' || suitChar == ' ' || suitChar == '\t');
            // printf("THIS IS WHAT I GOT: %c\n", suitChar);
            valueidx = validateCard(suitChar, 1);
            if(valueidx == -1){
                printf("Wrong suit value, retry in the possible values.\n");
                printf("Enter card: ");
            } else {
                hand[i][1] = valueidx;
            }
        }while(valueidx == -1);

        // printf("Recorded : %d%d\n", hand[i][0], hand[i][1]);
    }
    printf("\n");
    printf("Congrats!! ");
    classifyHand(hand);
    return 0;
}