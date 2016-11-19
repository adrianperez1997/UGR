# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding: utf-8
class Prize
    attr_accessor :treasures, :level
  def initialize(treasures,level)
    @treasures=treasures
    @level=level
  end
  
  def getTreasures(treasures)
    @treasures
  end
  
  def getLevel(level)
    @level
  end
  
  def to_s
    "Treasures:#{@treasures} \n Levels: #{@level}"
  end
end
