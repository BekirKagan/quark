# denovo-allocator

**denovo-allocator** is a C-based custom memory allocator interface that provides a default allocator interface, allowing you to either use the provided implementations or create your own custom allocator. The project aims to give you flexibility and control over memory management while keeping the interface simple and clean.

## Features
- Provides a **default allocator interface** to create your own allocator or use the provided implementations.
- Written in **C** for performance and flexibility.
- **CMake**-based build system for easy integration into your projects.

## Installation

### Clone the repository:
To get started with denovo-allocator, clone the repository:

```bash
git clone https://github.com/BekirKagan/denovo-allocator.git
```

### Build using CMake:

This project uses **CMake** to build. To build it as a static library, follow these steps:
```bash
cd denovo-allocator
cmake -S . -B build -G Ninja -D CMAKE_EXPORT_COMPILE_COMMANDS=1 -D CMAKE_BUILD_TYPE=Release -D DN_BUILD_EXAMPLES=1
cmake --build build
```
Once the build process is complete, the static library will be available for use.

### Usage:

1.  Include the header files from the **`include/denovo`** folder in your project.
2.  Link the **`denovo-allocator`** static library during your project’s build.
3.  You can either use the default allocator or implement your own custom allocator by conforming to the provided interface.

For more detailed examples, check out the **examples** folder.

## Example:

The **examples** folder contains several sample implementations showcasing how to integrate **denovo-allocator** into your project. Each example demonstrates different ways you can interact with the allocator, from simple memory allocation to more complex use cases.

```c
#include <denovo/dn_allocator.h>

int main() {
    // Example of using the default allocator
    void* ptr = dn_alloc(100);  // Allocate 100 bytes
    dn_free(ptr);               // Free the allocated memory
    return 0;
}

```
Check the **examples** folder for more complex demonstrations.

## Contributing

We welcome contributions to denovo-allocator! If you'd like to improve or extend the functionality of the library, feel free to fork the repository and submit a pull request. Please ensure that your changes adhere to the following guidelines:

-   **Bug reports** or **feature requests** should be opened as GitHub issues.
-   Contributions should be made via pull requests.
-   Please include relevant tests or examples where applicable.

## License

This project is licensed under the **GNU General Public License v3.0**. See the [LICENSE](LICENSE) file for full details.

## Contact

For questions, suggestions, or collaborations, feel free to reach out:

- Email: [kagankaraahmetoglu@hotmail.com](mailto:kagankaraahmetoglu@hotmail.com)
- Instagram: [@bekirkagankaraahmetoglu](https://www.instagram.com/bekirkagankaraahmetoglu)
