#include "PrevoyanteBehaviour.h"
#include "Bestiole.h"
#include "Milieu.h"
#include <cmath>
#include <vector>




PrevoyanteBehaviour* PrevoyanteBehaviour::clone(Bestiole* ownr)
{
    return new PrevoyanteBehaviour();
}


void PrevoyanteBehaviour::calculateDir(Milieu & monMilieu)
{
    //initialize
    int nbr_steps=EnvConfig::sNbrStepsPrediction;
    int nbr_neighbors=0;
    bool willCollide=false;
    double speed, nx, ny, dx, dy, orientation;
    math::vector2 temp_pos;
    std::vector<math::vector2> future_enemies_pos;
    std::vector<double> problematic_directions;

    //check for neighbors and calculate their future locations after nbr_steps
    for ( std::vector<shared_ptr<Bestiole>>::iterator it = monMilieu.getBestiolesList().begin() ; it != monMilieu.getBestiolesList().end() ; ++it ){
        //bestiole different from itself
        if ((**it).getIdentite() != owner->getIdentite()){
            //check if bestiole can see target
            if(owner->jeTeVois(**it)){
                if(EnvConfig::sDebugVision)  cout<<*owner<<" can sense "<<**it<<std::endl;
                nbr_neighbors +=1;
                //update future enemy position by number of steps in the future 
                temp_pos=(**it).getPosition();
                speed=(**it).getFinalSpeed();
                orientation=(**it).getOrientationRad();

                for(int i=1; i<=nbr_steps; ++i){

                    dx=10*cos(orientation)*speed;
                    dy=-10*sin(orientation)*speed;

                    nx = temp_pos[0] + dx;
                    ny = temp_pos[1] + dy;


                    if(nx < 0) {
                        orientation = M_PI - orientation;
                        temp_pos[0]=0.0;
                    }
                    else { 
                        if(nx > monMilieu.getWidth() - 1){
                          orientation = M_PI - orientation;
                          temp_pos[0]=monMilieu.getWidth();  
                        }
                        else{
                          temp_pos[0]=nx;
                        }    
                    }

                    if(ny < 0) {
                        orientation = - orientation;
                        temp_pos[1]=0.0;
                    }
                    else { 
                        if(ny > monMilieu.getHeight() - 1){
                          orientation = - orientation;
                          temp_pos[1]=monMilieu.getHeight();  
                        }
                        else{
                          temp_pos[1]=ny;
                        }    
                    }
                }
                //cout<<"NEIGHBOR: speed is : "<<speed<<" and current pos : "<<(**it).getPosition()<<" and future pos : "<<temp_pos<<endl;
                future_enemies_pos.push_back(temp_pos);
            }
        }
    }

    //calculate escape direction
    if(nbr_neighbors!=0){
        //for(int i=0; i<360; i++){
            willCollide=false;

            //update self future position by number of steps in the future 
            temp_pos=owner -> getPosition();
            speed=owner -> getFinalSpeed();
            orientation=owner->getOrientationRad();//*180.0/M_PI;

            for(int step=1; step<=nbr_steps; ++step){

                dx=10*cos(orientation)*speed;
                dy=-10*sin(orientation)*speed;

                nx = temp_pos[0] + dx;
                ny = temp_pos[1] + dy;


                if(nx < 0) {
                    orientation = M_PI - orientation;
                    temp_pos[0]=0.0;
                }
                else { 
                    if(nx > monMilieu.getWidth() - 1){
                        orientation = M_PI - orientation;
                        temp_pos[0]=monMilieu.getWidth();  
                    }
                    else{
                        temp_pos[0]=nx;
                    }    
                }

                if(ny < 0) {
                    orientation = - orientation;
                    temp_pos[1]=0.0;
                }
                else { 
                    if(ny > monMilieu.getHeight() - 1){
                        orientation = - orientation;
                        temp_pos[1]=monMilieu.getHeight();  
                    }
                    else{
                        temp_pos[1]=ny;
                    }    
                }
            }
            for(std::vector<math::vector2>::iterator it = future_enemies_pos.begin(); it != future_enemies_pos.end(); ++it){
                //cout<<temp_pos<<"   ##  "<<(*it)<<"    and distance  "<<math::vector2::distance(temp_pos, (*it))<<endl;
                if(math::vector2::distance(temp_pos, (*it))<4*owner->getAFF_SIZE()){
                    willCollide=true;
                    cout<<"we will collide"<<endl;
                    //cout<<"PREV: speed is : "<<speed<<" and current pos : "<<owner -> getPosition()<<" and future pos : "<<temp_pos<<endl;
                    break;
                }
                
            }
            if(willCollide){
                problematic_directions.push_back(orientation);
            }
            else{
            //cout<<"........."<<endl;
            }
        //}
        
        
        //if no safe directions return same else return random safe direction
        if(problematic_directions.size()==0){
            angle_rad=owner->getOrientationRad();
        }
        else{
            angle_rad=M_PI/4+problematic_directions[0];
            cout<<"escape orientation :"<<angle_rad<<endl;
        }
    }else{
       angle_rad=owner->getOrientationRad(); 
    }
    
}
