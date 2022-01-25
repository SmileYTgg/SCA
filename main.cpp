#include <iostream>

#include <SCA/Resources/Text/TextResource.hpp>
#include <SCA/Resources/Resources.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;

    SCA::Resources::TextResource text("master", "test");

    SCA::Resources::Resources resources;
    resources.countChangedInstances();

    return 0;
}
