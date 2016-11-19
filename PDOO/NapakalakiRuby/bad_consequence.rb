a# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding: utf-8
  
class BadConsequence
    attr_accessor :text, :levels, :nVisibleTreasures, :nHiddenTreasures, :death, :specificVisibleTreasures, :specificHiddenTreasures
  private_class_method:new
  def initialize(aText, someLevels, someVisibleTreasures, someHiddenTreasures, 
someSpecificVisibleTreasures, someSpecificHiddenTreasures, death) 
    @text = aText
    @levels = someLevels
    @nVisibleTreasures = someVisibleTreasures
    @nHiddenTreasures = someHiddenTreasures
    @specificVisibleTreasures = someSpecificVisibleTreasures
    @specificHiddenTreasures = someSpecificHiddenTreasures
    @death = death
  end
  
  private_class_method :new
  
  def BadConsequence.newLevelNumberOfTreasures(aText, someLevels, 
someVisibleTreasures, someHiddenTreasures)
    new(aText, someLevels,someVisibleTreasures, someHiddenTreasures,[],Array.new,false)
  end
  
  def BadConsequence.newLevelSpecificTreasures (aText, someLevels,                          
someSpecificVisibleTreasures, someSpecificHiddenTreasures)
    new(aText, someLevels,0, 0,someSpecificVisibleTreasures,someSpecificHiddenTreasures,false)
  end
  
    def BadConsequence.newDeath (aText)
    new(aText, 0,0, 0,[],[],true)
  end

  
  def getText(text)
    @text
  end
  
  def getLevels(levels)
    @levels
  end
  
  def getNVisibleTreasures
    @nVisibleTreasures
  end
  
  def getNHiddenTreasures
    @nHiddenTreasures
  end
  
  def getDeath
    @death
  end
  
  def to_s
    "Text:#{@text} \n Niveles: #{@levels}\n Visible treasures #{@nVisibleTreasures}
\n Hidden treasures: #{@nHiddenTreasures}\n Death: #{@death}"
  end
  
end
