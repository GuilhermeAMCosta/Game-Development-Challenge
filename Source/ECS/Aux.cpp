#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
	std::ifstream mapFile;
	std::string line;

	mapFile.open("map.txt");

	if(!mapFile){ //ou (arq.fail()) a exclamaçao é o not logico
		printf("Não abriu o arquivo\n");
		exit(1);//finaliza o programa, 0 com sucesso ou maior de 0 caso não finalizou com sucesso
	}

	int i = 0;
	while(i<20){
		getline(mapFile, line);
		std::cout << line[0] << std::endl;
		i++;
	}

if(!mapFile){ //ou (arq.fail()) a exclamaçao é o not logico
	printf("não abriu o arquivo\n");
exit(1);//finaliza o programa, 0 com sucesso ou maior de 0 caso não finalizou com sucesso
}
 //    for(i = 0; i < 19; i++){
 //    	line = mapFile.getline();
 //    	printf("%s\n",line );
 //    	i++;
 //    }
    mapFile.close();

	// int srcX, srcY;


	// for(int y = 0; y < 20; y++){
	// 	for(int x = 0; x < 25; x++){
	// 		mapFile.get(c);
	// 		srcY = atoi(&c);

	// 		mapFile.get(c);
	// 		srcX = atoi(&c);

	// 		std::cout << srcX << srcY << std::endl;

	// 		mapFile.ignore();
	// 	}
	// }

	// mapFile.close();

}
