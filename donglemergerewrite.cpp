//					dec			hex
//final file size	8650752,	0x840000
//file 1			8388608,	0x800000
//file 2 			262144,		0x40000

#include <filesystem>
#include <iostream>
#include <fstream>

int main() {


	std::string dongleFilePathInput;
	std::cout << "file path: ";
	std::cin >> dongleFilePathInput;
	std::filesystem::path dongleFilePath(dongleFilePathInput);
	
	std::string dongleFileName = dongleFilePath.filename().string();
	std::string eccFileName = dongleFilePath.stem().string() + "_spr.ic002";
	std::string mergedFileName = dongleFilePath.stem().string() + "_merged.ic002";
	
	std::ifstream dongleDataFile{ dongleFileName, std::ios::binary };
	std::ifstream eccDataFile{ eccFileName, std::ios::binary};
	std::ofstream outputFile{ mergedFileName, std::ios::binary | std::ios::app};
	
	char bufferDongle[0x200];
	char bufferECC[0x10];
	int runcount = 0;

		while (runcount != 16384) {
			runcount = runcount + 1;
			std::cout << "page " << runcount << " merged.\n" << std::endl;
			dongleDataFile.read(bufferDongle, 0x200);
			outputFile.write(bufferDongle, 0x200);
			eccDataFile.read(bufferECC, 0x10);
			outputFile.write(bufferECC, 0x10);
		}

		std::cout << "done\n" << std::endl;
		return 0;
	
	

}