#include <iostream>
#include "Array.hpp"

int main() {
	try {
		// デフォルトコンストラクタのテスト
		Array<int> defaultArray;
		std::cout << "Default array created. Size: " << defaultArray.size() << std::endl;

		// サイズ指定コンストラクタのテスト
		unsigned int n = 5;
		Array<int> sizedArray(n);
		std::cout << "Sized array created with size: " << sizedArray.size() << std::endl;

		// 要素の初期値を確認
		for (unsigned int i = 0; i < sizedArray.size(); i++) {
			std::cout << "sizedArray[" << i << "] = " << sizedArray[i] << std::endl;
		}

		// 値の代入と取得
		for (unsigned int i = 0; i < sizedArray.size(); i++) {
			sizedArray[i] = i * 10;
		}
		for (unsigned int i = 0; i < sizedArray.size(); i++) {
			std::cout << "Updated sizedArray[" << i << "] = " << sizedArray[i] << std::endl;
		}

		// コピーコンストラクタのテスト
		Array<int> copiedArray = sizedArray;
		std::cout << "Copied array created. Size: " << copiedArray.size() << std::endl;

		// コピー後に独立性を確認
		copiedArray[0] = 999;
		std::cout << "sizedArray[0]: " << sizedArray[0] << std::endl;
		std::cout << "copiedArray[0]: " << copiedArray[0] << std::endl;

		// 代入演算子のテスト
		Array<int> assignedArray;
		assignedArray = sizedArray;
		std::cout << "Assigned array created. Size: " << assignedArray.size() << std::endl;

		// 独立性の確認
		assignedArray[1] = 888;
		std::cout << "sizedArray[1]: " << sizedArray[1] << std::endl;
		std::cout << "assignedArray[1]: " << assignedArray[1] << std::endl;

		// 範囲外アクセスのテスト
		try {
			std::cout << "Accessing out of bounds: " << sizedArray[10] << std::endl;
		} catch (const std::exception& e) {
			std::cerr << "Exception caught: " << e.what() << std::endl;
		}

	} catch (const std::exception& e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
