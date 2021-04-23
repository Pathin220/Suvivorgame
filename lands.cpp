#include "lands.h"
#include <stdlib.h>

using namespace std;

Land* getRandomLand(){
     LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS );
    
    switch(selection){
        case LAKE:
        return new Lake;
        break;
        
        case FOREST:
        return new Forest;
        break;
        
        case DESERT:
        return new Desert;
        break;
        
        case SWAMP:
        return new Swamp;
        break;
        
        case MOUNTAIN:
        return new Mountain;
        break;
        
        case PASTOR:
        return new Pastor;
        break;
        
        case VILLAGE:
        return new Village;
        break;
        
        case GRAVEYARD:
        return new Graveyard;
        break;
        
        default:
        return new Lake;
        break;
    }
}

string Lake ::getShortDescription(){
    return "lake";
    
}

string Lake::getLongDescription(){
    return "You arrive at a large lake filled with clear sparkling water. ";
    
}

string Lake::visit(Player& p){
    string description = "You drink from the lake, replenshing your thirst";
    p.setThirst(p.getThirst() + 5);
    return description;
    
}
 
 string Forest::getShortDescription(){
     return "forest";
     
 }   
 
 string Forest::getLongDescription(){
     
     return "You arrive in dense forest filled with trees and foliage.";
     
 }
    
    string Forest::visit(Player& p){
        string description = "You forage for berries but find nothing.";
        
        int chance = rand() % 100;
        
        //Chance to find some berries
        if(chance > 50){
            description = "You foraged for berries in the forest and found some!";
           p.setHunger(p.getHunger()+1);
            return description;
    }
   

//Chance to get mauled by bear
if(chance < 10 && chance > 5){
    description = "You are attacked by a hungry bear in the woods!" ;
    p.setHealth(p.getHealth() - 1);
    
}

//Chance to get double mauled
if(chance < 5){
    description = "You are attacked by two very large bears!" ;
    int newHealth = (int)p.getHealth() - 2;
    newHealth = newHealth < 0 ? 0 : newHealth;
    p.setHealth(newHealth);
    
}
return description;

}


string Desert:: getShortDescription(){
    return "desert";
}

string Desert:: getLongDescription(){
    return "You arrive in a extremely hot, dry desert";
    
}

string Desert::visit(Player& p){
    string description = "The heat of the desert makes you dehydrated.";
     p.setThirst(p.getThirst() - 2);
    
    return description;
}

    string Swamp:: getShortDescription(){
    return "swamp";
}

    string Swamp:: getLongDescription(){
    return "You arrive in a extremely muddy, humid swamp";
}

string Swamp::visit(Player& p){
    string description = "You drink swampy water , replenshing your thirst but at a cost.";
    p.setThirst(p.getThirst() + 2);
    p.setHunger(p.getHunger() - 2);
    return description;
    
   /* int chance = rand() % 100;
    //Chance to get stuck in the mud
/*if(chance > 40) {
    description = "You fall into a deep pit of mud up to your neck!" ;
    p.setHunger(p.getHunger() - 2);
    //newThirst = newThirst < 0 ? 0 : newThirst;
    //p.setThirst(newThirst);
} 

//Chance to get mauled by alligator
if(chance < 60){
    description = "You are attacked by a alligator!" ;
    p.setHealth(p.getHealth() - 2);
}*/
return description;
}

 string Mountain::getShortDescription(){
     return "mountain";
     
 }   
 string Mountain::getLongDescription(){
     
     return "You arrive on a rocky terrian and the altitude that is very high.";
     
 }
    
    string Mountain::visit(Player& p){
        string description = "You climb the mountain for a better view around the surrounding area.";
        
        int chance = rand() % 100;
        
        //Chance to find some berries
        if(chance > 90){
            description = "You lose your footing and fall down the mountain!";
            p.setHealth(p.getHealth() - 4);
            }
   return description;
}

 string Pastor::getShortDescription(){
     return "pastor";
 }   
 string Pastor::getLongDescription(){
     
     return "You arrive in a open pastor field with the fields as tall you.";
 }
    string Pastor::visit(Player& p){
        string description = "You look around for anything to help your hunger.";
        
        int chance = rand() % 100;
        
        //Chance to find apple tree
        if(chance > 10){
            description = "You happen to spot an apple tree!";
           p.setHunger(p.getHunger()+1);
    }
    
    return description;
    }
    
    
     string Village::getShortDescription(){
     return "village";  
 }   
 
 string Village::getLongDescription(){
     
     return "You stubly across a old village.";
     
 }
    string Village::visit(Player& p){
        string description = "You look arond for a village doctor, but couldn't find one.";
        
        int chance = rand() % 100;
        
        //Chance to get feed by the villagers
        if(chance > 50){
            description = "The village has no doctor, but they are willing to feed you";
           p.setHunger(p.getHunger()+2);
           p.setThirst(p.getThirst()+3);
            return description;
    }
   

//Chance for a doctor to be there
if(chance < 25 && chance > 15){
    description = "You are in luck there happens to a village doctor!" ;
    p.setHealth(p.getHealth() + 3);
}

//Chance to get attacked by villagers
if(chance < 10){
    description = "You are attacked by the villagers for being an outsider!" ;
    int newHealth = (int)p.getHealth() - 2;
    newHealth = newHealth < 0 ? 0 : newHealth;
    p.setHealth(newHealth);
}
return description;
}
string Graveyard:: getShortDescription(){
    return "graveyard";
}

string Graveyard:: getLongDescription(){
    return "You come across a run down graveyard where the bodies were not properly burried";
    
}

string Graveyard::visit(Player& p){
    string description = "You start to feel sick to your stomach from the smell.";
    
    p.setHealth(p.getHealth() - 1);
    return description;
}
