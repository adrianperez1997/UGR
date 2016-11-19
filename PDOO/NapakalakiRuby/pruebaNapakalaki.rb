# To change this license header, choose License Headers in Project Properties.
# To change this template file, choose Tools | Templates
# and open the template in the editor.
#encoding: utf-8

require_relative "prize.rb"
require_relative "bad_consequence.rb"
require_relative "monster.rb"
require_relative "treasure_kind.rb"

class PruebaNapakalaki
    
  @@monsters = Array.new
    attr_accessor :monsters
  def combatten
  
    puts("\n\n MONSTRUOS CON NIVELES MAYOR QUE 10\n\n")
 
    i=0
    while(i<@@monsters.size)
        if((@@monsters[i].level) > 10)
          puts("\n" + @@monsters[i].to_s())
        end
      i+=1
  end
end

  
def perdidaniveles
  
   puts("\n\n PERDIDA DE NIVELES\n\n")
  
   i=0
    while(i<@@monsters.size)
        if(@@monsters[i].level > 0 )
                  puts("\n" + @@monsters[i].to_s())
        end
      i+=1
end
end

def ganancias

  puts("\n\nGANANCIAS DE NIVELES\n\n")
        
      i=0
    while(i<@@monsters.size)
            if(@@monsters[i].prize.level > 1)
                puts("\n" + @@monsters[i].to_s())
            end      
      i+=1
        end
end
  def perdidatesoros(treasure)

        puts("\n\nPERDIDA DE TESOROS\n\n");

    @@monsters.each do |m|
 
        for i in(0..(@@monsters.size - 1))
          if (treasure==m.BadConsequence.specificHiddenTreasures[i] or treasure==m.BadConsequence.specificVisibleTreasures[i])# || m.BadConsequence.specificHiddenTreasures[i].include?(treasure)) 
          puts("\n" + m.to_s())
          end
        end
      end

    end
     
  
  def crearcartas
prize = Prize.new(3,2) 
badConsequence = BadConsequence.newLevelNumberOfTreasures('Pierdes 5 niveles y 3 
tesoros visibles',5 , 3, 0)
@@monsters << Monster.new('El rey de rosado',11,prize,badConsequence)

prize = Prize.new(4,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Te atrapan para llevarte 
de fiesta y te dejan caer en mitad del vuelo. Descarta 1
mano visible y 1 mano oculta', 0,[TrearureKind::ONEHAND],[TrearureKind::ONEHAND])
@@monsters<< Monster.new('Demonios de Magaluf', 2, prize,badConsequence)

prize = Prize.new(2,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Pierdes tu armadura
visible y otra oculta', 0,[TrearureKind::ARMOR],[TrearureKind::ARMOR])
@@monsters<< Monster.new('Demonios de Magaluf', 8, prize,badConsequence)

prize = Prize.new(1,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Embobados con el lindo
primigenio te descartas de tu casco visible', 0,[TrearureKind::HELMET],[])
@@monsters<< Monster.new('Tenochtitlan', 2, prize,badConsequence)  

prize = Prize.new(1,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('El primordial bostezo
contagioso. Pierdes el calzado visible', 0,[TrearureKind::SHOES],[])
@@monsters<< Monster.new('El sopor de Dunwich', 2, prize,badConsequence) 

prize = Prize.new(3,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Pierdes todos tus tesoros
visibles', 0,[TrearureKind::SHOES][TrearureKind::ARMOR][TrearureKind::HELMET][TrearureKind::ONEHAND][TrearureKind::ONEHAND],[])
@@monsters<< Monster.new('El gorron en el umbral', 13, prize,badConsequence)   

prize = Prize.new(2,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Pierdes la armadura
visible', 0,[TrearureKind::ARMOR],[])
@@monsters<< Monster.new('H.P. Munchraft', 6, prize,badConsequence)   
 
prize = Prize.new(1,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Sientes bichos bajo la
ropa. Descarta la armadura visible', 0,[TrearureKind::ARMOR],[])
@@monsters<< Monster.new('Necrofago', 13, prize,badConsequence)   

prize = Prize.new(1,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Toses los pulmones y
pierdes 2 niveles.', 2,0,0)
@@monsters<< Monster.new('Flecher', 2, prize,badConsequence)  

prize = Prize.new(2,1)
badConsequence = BadConsequence.newLevelSpecificTreasures(' Estos monstruos resultan
bastante superficiales y te aburren mortalmente. Estas muerto')
@@monsters<< Monster.new('Los hondos', 8, prize,badConsequence)   

prize = Prize.new(2,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Pierdes 2 niveles y 2
tesoros ocultos.', 2,0,2)
@@monsters<< Monster.new('Semillas de Cthulhu', 4, prize,badConsequence) 
  
prize = Prize.new(2,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Te intentas escaquear.
Pierdes una mano visible.', 0,[TrearureKind::ONEHAND],[])
@@monsters<< Monster.new('Dameargo', 1, prize,badConsequence)  

prize = Prize.new(2,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Da mucho asquito.
Pierdes 3 niveles.', 3,0,0)
@@monsters<< Monster.new('Pollipolipo volante', 3, prize,badConsequence)

prize = Prize.new(3,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('No le hace gracia que
pronuncien mal su nombre. Estas muerto.')
@@monsters<< Monster.new('Yskhtihyssg-Goth', 14, prize,badConsequence)

prize = Prize.new(3,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('La familia te atrapa.
Estas muerto.')
@@monsters<< Monster.new('Familia feliz', 1, prize,badConsequence)  

prize = Prize.new(2,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('La quinta directiva
primaria te obliga a perder 2 niveles y un tesoro 2 manos visible',2,[TrearureKind::BOTHHAND],[])
@@monsters<< Monster.new('Roboggoth', 8, prize, badConsequence)

prize = Prize.new(1,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Te asusta en la noche.
Pierdes un casco visible.',0,[TrearureKind::HELMET],[])
@@monsters<< Monster.new('El espia sordo', 5, prize, badConsequence)

prize = Prize.new(2,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Menudo susto te llevas.
Pierdes 2 niveles y 5 tesoros visibles.',2,5,0)
@@monsters<< Monster.new('Tongue', 19, prize, badConsequence)

prize = Prize.new(2,1)
badConsequence = BadConsequence.newLevelSpecificTreasures('Te faltan manos para
tanta cabeza. Pierdes 3 niveles y tus tesoros visibles de las manos.',3,
[TrearureKind::SHOES][TrearureKind::ARMOR][TrearureKind::HELMET][TrearureKind::ONEHAND][TrearureKind::ONEHAND],[])
@@monsters<< Monster.new('Bicefalo', 21, prize, badConsequence)
  end
  
prueba = PruebaNapakalaki.new

prueba.crearcartas

prueba.combatten

prueba.perdidaniveles
  
prueba.ganancias

prueba.perdidatesoros(TreasureKind::ONEHAND)


end