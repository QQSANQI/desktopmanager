#include "FileCLassifier.h"
#include "jsonconfig_loader.h"
#include "Types&Rules.h"
/*完成了基本按规则分类功能,但是嵌套太多*/
JsonConfigLoader balabala;
bool FileCLassifier::result() const{return Is_classed;}
//分类函数；参数：文件路径列表，规则路径；s
void FileCLassifier::classFile(const vector<fs::path>& filePath, const fs::path& rulePath)
{
	for (const auto& caterule : balabala.configloader(rulePath)) {
	//CategoryRule caterule = balabala.configloader(rulePath)[index];//加载配置文件
		for (const auto& file : filePath)
		{
			string extension = file.extension().string();
			//检查文件扩展名是否在规则中
			if (std::find(caterule.extension.begin(), caterule.extension.end(), extension) != caterule.extension.end())//此处的判断条件是存在于规则中，详见find（）
			{
				fs::path targetDir = caterule.targetPath;
				//创建目标目录（如果不存在）
				if (!fs::exists(targetDir))
				{
					fs::create_directories(targetDir);
				}
				//移动文件到目标目录
				fs::path targetPath = targetDir / file.filename();
				try
				{
					fs::rename(file, targetPath);//冲突时可能报错，待添加处理机制
				}
				catch (fs::filesystem_error& e)
				{
					std::cerr << "Error moving file " << file << " to " << targetPath << ": " << e.what() << std::endl;
				}
				ClassedFiles.push_back(targetPath.string());//记录
			}
		}
	}

}
