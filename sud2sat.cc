#include<iostream>



int encode(int a, int b, int c){
    return 81 * (a-1) + 9 * (b-1) + c;
}
bool isWildCard(char i)
{
    return !('1' <= i <= '9')
}

int main(){
    //Reading input
    char board[9][9];
    int num_assigned = 0;
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            std::cin >> board[i][j];
            if (!isWildCard(board[i][j])){
                num_assigned++;
            }
        }
    }
    // //Outputing SAT version of Puzzle
    std::cout<<"p cnf 729 "<<8829 + num_assigned<<std::endl;
    for (int x = 1; x <= 9; ++x){
        for (int y = 1; y <= 9; ++y){
            for (int z = 1; z <= 9; ++z){
                std::cout<<encode(x,y,z)<<" ";
            }
            std::cout<<"0";
            std::cout<<std::endl;
        }
    }
    for (int y = 1; y <= 9; ++y){
        for (int z = 1; z <= 9; ++z){
            for (int x = 1; x <= 8; ++x){
                for (int i = x+1; i <= 9; ++i){
                    std::cout<<"-"<<encode(x,y,z)<<" "<<"-"<<encode(i,y,z);
                }
                std::cout<<" 0";
                std::cout<<std::endl;
            }

        }
    }
    for (int x = 1; x <= 9; ++x){
        for (int z = 1; z <= 9; ++z){
            for (int y = 1; y <= 8; ++y){
                for (int i = y+1; i <= 9; ++i){
                    std::cout<<"-"<<encode(x,y,z)<<" "<<"-"<<encode(x,i,z);
                }
                std::cout<<" 0";
                std::cout<<std::endl;
            }

        }
    }
    for (int z = 1; z <= 9; ++z){
        for (int i =0; i <= 2; ++i){
            for (int j =0; j <= 2; ++j){
                for (int x = 1; x <= 3; ++x){
                    for (int y = 1; y <= 3; ++y){
                        for (int k = x+1; k <= 3; ++k){
                            std::cout<<"-"<<encode(3*i+x,3*j+y,z)<<" "<<"-"<<encode(3*i+x,3*j+k,z);
                        }
                        std::cout<<" 0";
                        std::cout<<std::endl;
                    }
                }
            }
        }
    }
    for (int z = 1; z <= 9; ++z){
        for (int i =0; i <= 2; ++i){
            for (int j =0; j <= 2; ++j){
                for (int x = 1; x <= 3; ++x){
                    for (int y = 1; y <= 3; ++y){
                        for (int k = x+1; k <= 3; ++k){
                            for (int l = 1; l <=3; ++l){
                                std::cout<<"-"<<encode(3*i+x,3*j+y,z)<<" "<<"-"<<encode(3*i+k,3*j+l,z);
                            }
                            std::cout<<" 0";
                            std::cout<<std::endl;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            if (!isWildCard(board[i][j]))
                std::cout << encode(i+1,j+1,board[i][j])<<" 0";
        }
        std::cout<<std::endl;
    }

    return 0;
}