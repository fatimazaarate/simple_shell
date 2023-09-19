
#include <stdio.h>
#include <stdlib.h>

#define malloc(size) my_malloc(size, __FILE__, __LINE__)
#define free(ptr) my_free(ptr)

char *_getpath(char *command);

typedef struct {
    void *ptr;
    const char *file;
    int line;
} Allocation;

Allocation *allocations = NULL;
size_t num_allocations = 0;

void *my_malloc(size_t size, const char *file, int line)
{
    void *ptr = malloc(size);

    if (ptr != NULL) {
        Allocation *new_allocations = realloc(allocations, (num_allocations + 1) * sizeof(Allocation));
        if (new_allocations != NULL) {
            allocations = new_allocations;
            allocations[num_allocations].ptr = ptr;
            allocations[num_allocations].file = file;
            allocations[num_allocations].line = line;
            num_allocations++;
        }
    }

    return ptr;
}

void my_free(void *ptr)
{
    for (size_t i = 0; i < num_allocations; i++) {
        if (allocations[i].ptr == ptr) {
            free(ptr);
            // Shift remaining elements to fill the gap
            for (size_t j = i; j < num_allocations - 1; j++) {
                allocations[j] = allocations[j + 1];
            }
            num_allocations--;
            break;
        }
    }
}

void print_memory_leaks()
{
    if (num_allocations > 0) {
        printf("Memory leaks detected:\n");
        for (size_t i = 0; i < num_allocations; i++) {
            printf("Allocated at %s:%d\n", allocations[i].file, allocations[i].line);
        }
    } else {
        printf("No memory leaks detected.\n");
    }
}

int main()
{
    char *path;

    path = _getpath("ls");
    printf("Path of ls: %s\n", path);

    path = _getpath("cd");
    printf("Path of cd: %s\n", path);

    path = _getpath("python");
    printf("Path of python: %s\n", path);

    print_memory_leaks();

    // Free remaining allocations
    for (size_t i = 0; i < num_allocations; i++) {
        free(allocations[i].ptr);
    }
    free(allocations);

    return 0;
}