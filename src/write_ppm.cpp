#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  std::ofstream file(filename,std::ios::out);
  if(!file) return false;

  if (num_channels == 3){//RGB
    file <<"P3\n"<<width<<" " << height<< "\n" << "255" <<std::endl;
  }
  else if (num_channels == 1){//gray
    file <<"P2\n"<<width<<" " << height<< "\n" << "255" <<std::endl;
  }

  for (int i = 0; i< width*height*num_channels;i++){
    if (i % width == 0 && i != 0){
          file << "\n";
    }
    file << int(data[i]) << " ";
  }

  file.close();
  if (!file.is_open()){
    return true;
  }

  return false;
  ////////////////////////////////////////////////////////////////////////////
}
