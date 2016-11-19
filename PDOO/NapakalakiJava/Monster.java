/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;

/**
 *
 * @author adrian97
 */
public class Monster {
    private String name;
    private int combatLevel;
    
    private Prize prize;
    private BadConsequence bc;
    
    public Monster(String name, int combatLevel, BadConsequence bc, Prize prize){
        this.name = name;
        this.combatLevel = combatLevel;
        this.bc = bc;
        this.prize = prize;
    }
    
    public String getName(){
        return name;
    }
    public int getcombatLevel(){
        return combatLevel;
    }
    public Prize getPrize(){
        return prize;
    }
    public BadConsequence getBadConsequence(){
        return bc;
    }
    
    public String toString(){
        return "Name = " + name +  " Combat level = " + Integer.toString(combatLevel) 
                + " Prize = " + prize + " Bad consequence = " + bc;
    }
    
}
