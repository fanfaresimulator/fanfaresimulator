#include "../include/ui.hpp"



void UI::Init(){
    window=new GameWindow();
    int size=partition.size();
    double time1,time2;
    for(int i=0;i<size;i++){
        time1=partition[i].get_timestamp();
        int key=partition[i].get_key();
        for(int j=i;j<size;j++){
            if(partition[j].get_key()==key){
               time2=partition[j].get_timestamp();
                window.add_note(new GuiNote(window,key,time1,time2));
                break;
            }
        }
    }
}