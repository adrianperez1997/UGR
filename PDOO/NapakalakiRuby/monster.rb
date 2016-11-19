# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding: utf-8
class Monster
    attr_accessor :name, :combatlevel, :BadConsequence, :prize, :level
  def initialize(name,combatLevel,prize,bc)
    @name = name
    @combatLevel = combatLevel
    @prize = prize
    @badConsequence = bc       
  end
  
  def getName
    @name
  end
  
  def getCombatLevel
    @combatLevel
  end
  
  def getPrize
    @prize
  end
  
  def getBadConsequence
    @badConsequence
  end
  
  
  def to_s
    "Name: #{@name} \n CombatLevel: #{@combatLevel}\n Prize: #{@prize}
\n Bad Consequence: #{@badConsequence}"
  end
end
