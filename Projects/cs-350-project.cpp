#include <iostream>
using namespace std;
#include <vector>
#include <ctime>
#include <random>

string puzzles[]{
"439186257581327469762549813246735198973861542158294736895473621624918375317652984",
"110001110000001000001000010011100100000101000001001110010000100000100000011100011" ,
"259837416436915728187642935968473251315286947724159863591328674642791583873564192",
"100100010010010010100010100010001010001001010010010001000100100010010010100010001",
"381649572276518439459327618628495713137862954945173286812734965593286147764951823",
 "100010001001001000010010100000010000101000000100010001010001001000100010100010000",
 "723859641489126735651347892842513976367492518195678423278931654516784239934265187",
 "110001000001010100000010001001000100001000100000100001001000100010010000000010010",
 "917483256534162987826957431693745812285319674471628593152894367348576129769231548",
 "100010000010001010000100000100001000001000100000010000010001000100001000010000001"
 };


string select_puzzle(){
    srand(time(0));
    int random_index = rand() % 10;
    return puzzles[random_index];
}

