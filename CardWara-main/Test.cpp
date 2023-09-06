#include <iostream>
#include <fstream>
#include <sstream>

#include <stdexcept>
using namespace std;


#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

#include "doctest.h"


TEST_CASE("before we start to play") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);
    //Check that we dealt them 52 cards
    bool allcards=( (p1.stacksize()+p2.stacksize())==52);
    CHECK(allcards);

    //Check that they have 0 cardswin
    bool wincards=( (p2.cardesTaken()+p1.cardesTaken())==0);
    CHECK(wincards);


    //check that we have really divided them properly and that there is a balance between them
    CHECK(p2.cardesTaken()==0);

    CHECK(p1.stacksize()==26);

    bool samecard= (p1.stacksize()==p2.stacksize());
    CHECK(samecard);

    //check that cant winner
    bool win=true;
    try{
        game.printWiner();
    }catch (std::exception ex) {
        win=false;
	}
    CHECK(win);


}


TEST_CASE("After a one moves") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    game.playTurn();

    //Check that there are still a total of 52 cards
    bool allcards=( (p1.stacksize()+p2.stacksize()+p2.cardesTaken()+p1.cardesTaken())==52);
    CHECK(allcards);

    //After one round he has a maximum of 25 cards left
    bool p1cards=( (p1.stacksize()<=25));
    CHECK(p1cards);

    bool p2cards=( (p2.stacksize()<=25));
    CHECK(p2cards);

    //After one round he has a min 2 cardswin
    bool cardswin=( (p2.cardesTaken()>=2|| p1.cardesTaken()>=2));
    CHECK(cardswin);

    //After one round this is the distribution that should be
    bool samecard= ((26-p1.stacksize())==p2.cardesTaken());
    CHECK(samecard);

   


    //can not ce winner
    bool win=true;
    try{
        game.printWiner();
    }catch (std::exception ex) {
        win=false;
	}
    CHECK(win);

    CHECK( game.printLog()==game.printLastTurn());

}

TEST_CASE("end game") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1,p2);

    //check that they take out one card each time
    for (int i=0;i<5;i++) {
    game.playTurn();
    CHECK(p1.stacksize()==p2.stacksize() );
    }


    //check that they have nothing left
    game.playAll();
    bool allcards=( (p2.stacksize()==p1.stacksize()));
    CHECK(allcards);

    CHECK(p1.stacksize()==0);

    //check that all the cards are wincards
    bool whowinlastmove= ((p1.cardesTaken())+p2.cardesTaken()==52);
    CHECK(whowinlastmove);

    bool win=true;
    try{
        game.printWiner();
    }catch (std::exception ex) {
        win=false;
	}
    CHECK(win);

    
   

}

TEST_CASE("exception") {
    Player p1("Alice");
    Player p2("Bob");


    bool canthappen=true;
    try{
       Game game1(p1,p1);

    }catch (std::exception ex) {
        canthappen=false;
	}
    CHECK(canthappen);


    Player p5("Alice");
    Player p6("Bob");
    Game game3(p5,p6);
    game3.playAll();

    canthappen=true;
    try{
       game3.playTurn();

    }catch (std::exception ex) {
        canthappen=false;
	}
    CHECK(canthappen);

    Player p7("Alice");
    Player p8("Bob");
    Game game4(p7,p8);
    game4.playAll();

    canthappen=true;
    try{
       game4.playAll();

    }catch (std::exception ex) {
        canthappen=false;
	}
    CHECK(canthappen);

}