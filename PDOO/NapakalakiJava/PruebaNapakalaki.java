/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package napakalaki;
import java.util.ArrayList;
import java.util.Arrays;


/**
 *
 * @author adrian97
 */
public class PruebaNapakalaki {

    /**
     * @param args the command line arguments
     */
    static ArrayList<Monster> monstruos = new ArrayList();
    
    
    public static void CombatTen(){
        
        System.out.println("\n\n MONSTRUOS CON NIVELES MAYOR QUE 10\n\n");
        
    for(int i=0; i< monstruos.size(); i++){
        if(monstruos.get(i).getcombatLevel() > 10){
        System.out.println(monstruos.get(i).toString());
        }
    }
}
        public static void PerdidaNivelesBadConsequence(){
 
        System.out.println("\n\nPERDIDA DE NIVELES\n\n");
        
        for(int i=0; i< monstruos.size();i++){
            if((monstruos.get(i).getBadConsequence().getLevels() > 0 )&& 
               (monstruos.get(i).getBadConsequence().getNVisibleTreasures() == 0 )&& 
               (monstruos.get(i).getBadConsequence().getNHiddenTreasures() == 0 )&& 
               (monstruos.get(i).getBadConsequence().getsVisibleTreasures().isEmpty()) &&
               (monstruos.get(i).getBadConsequence().getsHiddenTreasures().isEmpty())){
                System.out.println(monstruos.get(i).toString());
            }
        }
    }
     public static void Ganancias(){
    
        System.out.println("\n\nGANANCIA DE NIVELES\n\n");
        
        for(int i=0;i<monstruos.size();i++){
            if(monstruos.get(i).getPrize().getLevel() > 1){
                System.out.println(monstruos.get(i).toString());}
        }
    }
        public static void PerdidaDeTesoros(TreasureKind kind){
       System.out.println("\n\nPERDIDA DE TESOROS\n\n");
        for(int i=0;i<monstruos.size();i++){
            if(monstruos.get(i).getBadConsequence().getsVisibleTreasures().contains(kind)||monstruos.get(i).getBadConsequence().getsHiddenTreasures().contains(kind)){
               System.out.println(monstruos.get(i).toString());
            }        
        }
        
    }
        
    public static void main(String[] args) {
        // TODO code application logic here

        BadConsequence bcElRey = new BadConsequence("Pierdes 5 niveles y 3 tesoros visibles", 5, 3, 0); 
        Prize pElRey = new Prize(3,2);
        monstruos.add(new Monster("El rey de rosado",11,bcElRey, pElRey)); 
    
        
        BadConsequence bcDemonios = new BadConsequence("Te atrapan para llevarte de fiesta y "
           + "te dejan caer en mitad del vuelo. Descarta 1 mano visible y 1 mano oculta",0,
            new ArrayList(Arrays.asList(TreasureKind.ONEHAND)), new ArrayList(Arrays.asList(TreasureKind.ONEHAND)));
        Prize pDemonios = new Prize(4,1);
        monstruos.add(new Monster("Demonios de Magaluf", 2, bcDemonios,pDemonios));
    
        
        BadConsequence bcByakhees = new BadConsequence("Pierdes tu armadura visible y otra oculta",
                0,new ArrayList(Arrays.asList(TreasureKind.ARMOR)),new ArrayList(Arrays.asList(TreasureKind.ARMOR))); 
        Prize pByakhees = new Prize(2,1);
        monstruos.add(new Monster("3 Byakhees de bonanza",8,bcByakhees, pByakhees)); 
        
        
        BadConsequence bcTenochtitlan = new BadConsequence("Embobados con el lindo primigenio te descartas de tu "
                + "casco visible", 0, new ArrayList(Arrays.asList(TreasureKind.HELMET)), new ArrayList()); 
        Prize pTenochtitlan = new Prize(1,1);
        monstruos.add(new Monster("Tenochtitlan",2,bcTenochtitlan, pTenochtitlan));
        
        
        BadConsequence bcElSopor = new BadConsequence("El primordial bostezo contagioso."
                + " Pierdes el calzado visible", 0, new ArrayList(Arrays.asList(TreasureKind.SHOES)), new ArrayList()); 
        Prize pElSopor = new Prize(1,1);
        monstruos.add(new Monster("El sopor de Dunwich",2,bcElSopor, pElSopor));
        
        
        BadConsequence bcElGorron = new BadConsequence("Pierdes todos tus tesoros visibles",
                0,new ArrayList(Arrays.asList(TreasureKind.ARMOR,TreasureKind.SHOES,
                TreasureKind.BOTHHANDS,TreasureKind.HELMET)),new ArrayList()); 
        Prize pElGorron = new Prize(3,1);
        monstruos.add(new Monster("El gorron en el umbral",13,bcElGorron, pElGorron));
    
        
        BadConsequence bcHP = new BadConsequence("Pierdes la armadura visible", 0, 
                new ArrayList(Arrays.asList(TreasureKind.ARMOR)), new ArrayList()); 
        Prize pHP = new Prize(2,1);
        monstruos.add(new Monster("H.P. Munchcraft",6,bcHP, pHP));        
    
        
        BadConsequence bcNecrofago = new BadConsequence("Sientes bichos bajo la ropa. Descarta la armadura visible",
                0,new ArrayList(Arrays.asList(TreasureKind.ARMOR)), new ArrayList()); 
        Prize pNecrofago = new Prize(1,1);
        monstruos.add(new Monster("Necrófago",13,bcNecrofago, pNecrofago));       
        
        
        BadConsequence bcFlecher = new BadConsequence("Toses los pulmones y pierdes 2 niveles",2,0,0);
        Prize pFlecher = new Prize(1,1);
        monstruos.add(new Monster("Flecher",2,bcFlecher, pFlecher));
        
        
        BadConsequence bcLosHondos = new BadConsequence("Estos monstruos resultan bastante superficiales y te aburren"
                + "mortalmente. Estas muerto",true);
        Prize pLosHondos = new Prize(2,1);
        monstruos.add(new Monster("Los Hondos",8,bcLosHondos, pLosHondos));
        
        
        BadConsequence bcSemillas = new BadConsequence("Pierdes 2 niveles y 2 tesoros ocultos.",2,0,2);
        Prize pSemillas = new Prize(2,1);
        monstruos.add(new Monster("Semillas Cthulhu",4,bcSemillas, pSemillas));

        
        BadConsequence bcDameargo = new BadConsequence("Te intentas escaquear Pierdes una mano visible.",0,
                new ArrayList(Arrays.asList(TreasureKind.ONEHAND)),new ArrayList());
        Prize pDameargo = new Prize(2,1);
        monstruos.add(new Monster("Dameargo",1,bcDameargo, pDameargo));
        
        
        BadConsequence bcYskhtihyssg = new BadConsequence("No le hace gracia que pronuncien mal su nombre."
                + " Estas muerto",true);
        Prize pYskhtihyssg = new Prize(3,1);
        monstruos.add(new Monster("Yskhtihyssg-Goth",14,bcYskhtihyssg, pYskhtihyssg));
        
        
        BadConsequence bcFamilia = new BadConsequence("La familia te atrapa. Estas muerto.",true);
        Prize pFamilia = new Prize(3,1);
        monstruos.add(new Monster("Familia feliz",1,bcFamilia, pFamilia));

        
        BadConsequence bcRoboggoth= new BadConsequence("La quinta directiva primaria te obliga a "
                + "perder 2 niveles y un tesoro 2 manos visible",2,new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS))
                ,new ArrayList());
        Prize pRoboggoth = new Prize(2,1);
        monstruos.add(new Monster("Roboggoth",8,bcRoboggoth, pRoboggoth));
        
        
        BadConsequence bcEspia = new BadConsequence("Te asusta en la noche. Pierdes un casco visible.",0,
                new ArrayList(Arrays.asList(TreasureKind.BOTHHANDS)),new ArrayList());
        Prize pEspia = new Prize(1,1);
        monstruos.add(new Monster("El espia sordo",5,bcEspia, pEspia));
        
        
        BadConsequence bcTongue = new BadConsequence("Menudo susto te llevas. Pierdes 2 niveles y 5 tesoros visibles.",2,5,0);
        Prize pTongue = new Prize(2,1);
        monstruos.add(new Monster("Tongue",19,bcTongue, pTongue));
        
        
        BadConsequence bcBicefalo = new BadConsequence("Te faltan manos para tanta cabeza. Pierdes 3 niveles y tus "
                + "tesoros visibles de las manos",0,new ArrayList(Arrays.asList(TreasureKind.ARMOR,TreasureKind.SHOES,
                TreasureKind.BOTHHANDS,TreasureKind.HELMET)),new ArrayList());
        Prize pBicefalo = new Prize(2,1);
        monstruos.add(new Monster("Bicefalo",21,bcBicefalo, pBicefalo)); 
        
    CombatTen();
    
    PerdidaNivelesBadConsequence();
    
    Ganancias();
    
    PerdidaDeTesoros(TreasureKind.ARMOR);
    }

    
}
