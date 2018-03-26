
#include "SimpleTemplateEngine.h"
namespace nets{
    View::View(std::string InputString) {
        this->InputString=InputString;
    }
    View::View() {}
    View::~View() {}
    std::string View::GetString() const {
        return this->InputString;
    }
    std::string View::Render(const std::unordered_map<std::string, std::string> &model) const {
        std::string OutputString="";
        std::string InputString = GetString();
        std::smatch Matches;
        std::regex Pattern {R"("{"{"w+"}"})"};
        while (std::regex_search(InputString, Matches, Pattern)){
            for(auto Value: Matches){
                std::string Word =  Value.str().substr(2,Value.str().length()-4);
                OutputString+=Matches.prefix().str();
                if (model.find(Word)!=model.end()) OutputString+=model.find(Word)->second;
            }
            InputString=Matches.suffix();
        }
        OutputString+=InputString;
        return OutputString;
    }
}
