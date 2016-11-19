/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;
import java.util.ArrayList;

/**
 *
 * @author adrian97
 */
public class BadConsequence {
    private String text;
    private int levels, nVisibleTreasures, nHiddenTreasures;
    private boolean death;
    
    public BadConsequence (String text, int levels, int nVisible, int nHidden){
        this.text = text;
        this.levels = levels;
        this.nVisibleTreasures = nVisibleTreasures;
        this.nHiddenTreasures = nHiddenTreasures; 
    }
    public BadConsequence(String text, boolean death){
        this.text = text;
        this.death = death;
    }
    private ArrayList<TreasureKind> specificVisibleTreasures = new ArrayList();
    private ArrayList<TreasureKind> specificHiddenTreasures = new ArrayList();

    public BadConsequence(String text, int levels, ArrayList<TreasureKind> tVisible,ArrayList<TreasureKind> tHidden){
        this.specificVisibleTreasures = tVisible;
        this.specificHiddenTreasures = tHidden;
    }
    

    public String getText(){
        return text;
    }
    public int getLevels(){
        return levels;
    }
    public int getNVisibleTreasures(){
        return nVisibleTreasures;
    }    
    public int getNHiddenTreasures(){
        return nHiddenTreasures;
    }
    public ArrayList getsHiddenTreasures(){
        
        return this.specificHiddenTreasures;
    }
    
    public ArrayList getsVisibleTreasures(){
        
        return this.specificVisibleTreasures;
    }
    public boolean getDeath(){
        return death;
    }
    
    public String toString(){
        return "Text = " + text +  " levels = " + Integer.toString(levels) + " Visible treasures = "
                + Integer.toString(nVisibleTreasures) + " Hidden treasures = " + Integer.toString(nHiddenTreasures);
    }
}
