#include "openning.h"

//Opening of the file

std::vector<Crossing> knowledge()
{
    std::ifstream fichier("hereka.txt",std::ifstream::in);

    if(fichier)
    {

        std::vector<Crossing> allStates;

        std::string content;

        while  (std::getline(fichier, content))
        {
            int x1 = content[0:2];
            int y1 = content[3:5];
            Crossing state(x1,y1);

            std::vector<Crossing>::iterator it;

            //We look if the state already exist in allState
            bool done = false
            for( it = allStates.begin() ; it != allStates.end() ; it++)
            {
                Crossing curent_state = *it;

                if(curent_state.getState() == state.getState()) // The state have already been visited
                {
                    state = curent_state;

                    //Update of this state
                    Crossing next(content[-5:-3], content[-2:]);
                    state.setSucessor(next, content[6:-6]);

                    done = true;
                }
            }

            if(done== false) // if the state have not been visited
            {
                //Add this state to the knowledge base
                Crossing next(content[-5:-3], content[-2:]);
                state.setSucessor(next, content[6:-6]);
                allStates.append(state);
            }
        }


        fichier.close();
        return allStates;
    }

    else
    {
        std::cerr << "File openning failed !" << std::endl;
        return -1;
    }
}
