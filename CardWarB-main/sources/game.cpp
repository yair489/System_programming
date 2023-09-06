#include "game.hpp"
#include "player.hpp"

using namespace std;
#include <iostream>
#include <stdexcept>
#include <string>
#include <random>
using namespace std;

#include <vector>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <chrono>

namespace ariel{
     Game::Game(Player &playe1, Player &playe2) : player1(playe1), player2(playe2)
        {
            this->lastTurn="";
            this->log="";
            this->numberOfTurn=0;
            this->draws=0;
            this->winnwer="nobody";
            if(player1.isinPlaying()|| player2.isinPlaying()){throw invalid_argument("The player is busy"); }
            //create the card

            vector<card> allCards;
            for(int i=1; i<=4 ; i++){
                for(int j=1; j<=13 ; j++){
                    allCards.push_back(card(Numberr(j),Type(i)));
                }
            }
            // https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
            //shuffle the card
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::default_random_engine e(seed);
            shuffle(allCards.begin(), allCards.end(), e);

            //divide the cards
            for(int i=0;i<26; i++){
                player1.addCard(allCards.back());
                allCards.pop_back();
            }
            while(!allCards.empty()){
            player2.addCard(allCards.back());
            allCards.pop_back();
            }
            // cout<<player2.stacksize()<<endl;
            this->player1.setisPlaying(true);
            this->player2.setisPlaying( true);    
        }


    
    void Game::playTurn(){
        if(&player1==&player2){throw invalid_argument("The player is busy"); }//check here beacuse the studentTest
        if ((!player1.isinPlaying())|| (!player2.isinPlaying())   ){
            throw invalid_argument("The player is busy");}
        if(this->numberOfTurn>25){
            throw invalid_argument("The player is finish to play");}

        this->lastTurn="";
        this->numberOfTurn++;

        card card1=player1.getCard();
        card card2=player2.getCard();
        player1.removefromPlayerCard();
        player2.removefromPlayerCard();

        this->lastTurn = "\nTurn " + ::to_string(this->numberOfTurn) + "\n" + player1.getName() + " play " + card1.printcard() + " " +
        player2.getName() + " played " + card2.printcard() + " ";

        int CountingRounds=1;
        bool untildraw=false;
        if( (card1.getNumberr()==card2.getNumberr())&& (player1.stacksize()>=1&&player2.stacksize()>=1)){
            untildraw=true;
        }
        //if there is draw
        while(untildraw){
            this->draws++;
            this->lastTurn+= "draw!.\n";
            /*This is the reversed card. If there is one card left, don't turn it over, just open a new card*/
            if(player1.stacksize()>1&&player2.stacksize()>1){
                card1=player1.getCard();
                card2=player2.getCard();
                player1.removefromPlayerCard();
                player2.removefromPlayerCard();
                CountingRounds++;
                this->numberOfTurn++;
                this->lastTurn += "\none card face down" + ::to_string(this->numberOfTurn) +"\n ";
            }
            card1=player1.getCard();
            card2=player2.getCard();
            player1.removefromPlayerCard();
            player2.removefromPlayerCard();
            CountingRounds++;
            this->numberOfTurn++;
  
            /*If there is still a draw but no cards, you should exit the loop*/
            if( !(card1.getNumberr()==card2.getNumberr())||this->numberOfTurn>25|| !(player1.stacksize()>=1&&player2.stacksize()>=1)){
                untildraw=false;
            }
            this->lastTurn += "\n" + ::to_string(this->numberOfTurn) +": " + player1.getName() + " played " + card1.printcard() + " " +
            player2.getName() + " played " + card2.printcard() + ".\n ";
        }

        /*check who won*/
        if(card1.getNumberr()>2&& Numberr(1)==card2.getNumberr()){
          this->lastTurn+= "in this turn, draws:"+::to_string(this->draws)+" and winner in this turn "+player2.getName()+"\n";
            for(int i=0;i<CountingRounds;i++){
                player2.addCardesTaken();
                player2.addCardesTaken();
            }
        }else if(card1.getNumberr()==Numberr(1) &&2<card2.getNumberr()){
            this->lastTurn+= "in this turn, draws:"+::to_string(this->draws)+" and winner in this turn "+player1.getName()+"\n";
            for(int i=0;i<CountingRounds;i++){
                player1.addCardesTaken();
                player1.addCardesTaken();
            }
        }else if(card1.getNumberr()>card2.getNumberr()){
            this->lastTurn+= "in this turn, draws:"+::to_string(this->draws)+" and winner in this turn "+player1.getName()+"\n";
            for(int i=0;i<CountingRounds;i++){
                player1.addCardesTaken();
                player1.addCardesTaken();
            }
        }else if(card1.getNumberr()<card2.getNumberr()) {
            this->lastTurn+= "in this turn, draws:"+::to_string(this->draws)+" and winner in this turn "+player2.getName()+"\n";
            for(int i=0;i<CountingRounds;i++){
                player2.addCardesTaken();
                player2.addCardesTaken();
            }
        }else{//draw
            this->lastTurn+= "in this turn, draws:"+::to_string(this->draws)+" in this turn finish draw"+"\n";
            for(int i=0;i<CountingRounds;i++){
                player1.addCardesTaken();
            }
            for(int i=0;i<CountingRounds;i++){
                player2.addCardesTaken();
            }
        }
        /*finish to check who won*/
        if(!player1.stacksize()||!player2.stacksize()){

            player1.setisPlaying(false);
            player2.setisPlaying(false);

            if(player1.cardesTaken()>player2.cardesTaken()){
                this->winnwer=player1.getName();
            }else if(player1.cardesTaken()<player2.cardesTaken()) {
                this->winnwer=player2.getName();
            }else{
                this->winnwer="draw!!!";
            }
        }   
        this->log+=this->lastTurn;





    }
    void Game::playAll(){
        while(this->numberOfTurn<26 && player1.isinPlaying() && player2.isinPlaying()){
            Game::playTurn();
        }
    }

    void Game::printStats(){
        cout << "---------printStats---------" << endl;
        cout <<  player1.getName() << endl;
        cout << "cardesTaken " << player1.cardesTaken() << endl;
        cout << "Cards left: " << player1.stacksize() << endl;

        cout << player2.getName()  << endl;
        cout << "cardesTaken " << player2.cardesTaken() << endl;
        cout << "Cards left: " << player2.stacksize() << endl;

        cout << "until now the winner  "+this->winnwer;
        cout << endl;
    }


    void Game::printWiner(){
        if(player1.isinPlaying() || player2.isinPlaying()){return;}
                    cout <<"  printWiner" << endl;

        if(player1.cardesTaken()>player2.cardesTaken()){
            cout <<player1.getName() << endl;
        }if(player1.cardesTaken()<player2.cardesTaken()) {
            cout <<player2.getName() << endl;
        }else{
            cout <<"  draw!!" << endl;
        }
    }

}
