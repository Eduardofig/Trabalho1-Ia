Vim�UnDo� N��m��"��`��74dGtؤ�~ņ�����u                                      cE�]   
 _�                            ����                                                                                                                                                                                                                                                                                                                                                             cE�N     �                   �               5��                   
                      b      5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             cE�P     �                 �              5��                                                  �                                                  5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             cE�T     �                #include "aux.hpp>5��                                              5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             cE�W    �                #include "aux.hpp:5��                                              5�_�      	                      ����                                                                                                                                                                                                                                                                                                                                                 v       cEʘ     �                �             5��                                                �                                                �       	                                      5�_�      
           	           ����                                                                                                                                                                                                                                                                                                                                                 v       cEʝ     �                  �               5��                          �                     �                          �                     5�_�   	              
           ����                                                                                                                                                                                                                                                                                                                                                 v       cEʟ    �                namespace aux {   Udouble dist(const int from, const int to, std::vector<std::pair<int, int>> &vertices)   {   D    const int x1 = vertices[from].first, y1 = vertices[from].second;   @    const int x2 = vertices[to].first, y2 = vertices[to].second;       #    const double delta_x = x2 - x1;   #    const double delta_y = y2 - y1;       7    return sqrt(delta_x * delta_x + delta_y * delta_y);   }   }5��                          $                      �                          ~                      �                         �                     �                         �                     �                                             �    	                     ;                    �                         d                    �                          �                     5�_�   
                        ����                                                                                                                                                                                                                                                                                                                                                 v       cEʡ    �               namespace aux {5��                        !                     5�_�                       .    ����                                                                                                                                                                                                                                                                                                                                                 v       cE��    �               Y    double dist(const int from, const int to, std::vector<std::pair<int, int>> &vertices)5��       .                  R                      5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             cE�K   	 �                �             5��                                                �                                                �       
              
                 
       5�_�                            ����                                                                                                                                                                                                                                                                                                                                                             cE�\   
 �                #include <algorithm>5��                                                5�_�                           ����                                                                                                                                                                                                                                                                                                                                                             cE�I     �              �                     D    const int x1 = vertices[from].first, y1 = vertices[from].second;   @    const int x2 = vertices[to].first, y2 = vertices[to].second;       #    const double delta_x = x2 - x1;   #    const double delta_y = y2 - y1;       7    return sqrt(delta_x * delta_x + delta_y * delta_y);5��                                               5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             cE�I     �               5��                                                  5�_�                             ����                                                                                                                                                                                                                                                                                                                                                             cE�D     �              �                  dist(co5��                                                  5��