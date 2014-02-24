
#include <thread>
#include <memory>

#include <stdio.h>

class Foo
{
public:
    Foo() { printf("+++ Foo::Foo()\n"); }
    ~Foo() { printf("--- Foo::~Foo()\n"); }
    void process() { printf("... Foo::process()\n"); }
};

void worker(std::shared_ptr<Foo>& obj)
{
    printf("worker: spawned, obj %p use_count %ld\n",
        obj.get(),
        obj.use_count());

    // Do something useful with obj
    obj->process();
}

int main(int argc, char* argv[])
{
    printf("+++ main()\n");

    std::shared_ptr<Foo> obj(new Foo);

    printf("main: just created, obj %p use_count %ld\n",
        obj.get(),
        obj.use_count());

    std::thread w1(std::bind(worker, obj));

    printf("main: thread 1 spawned, obj %p use_count %ld\n",
        obj.get(),
        obj.use_count());

    std::thread w2(std::bind(worker, obj));

    printf("main: thread 2 spawned, obj %p use_count %ld\n",
        obj.get(),
        obj.use_count());

    w1.join();
    w2.join();

    printf("main: threads completed, obj %p use_count %ld\n",
        obj.get(),
        obj.use_count());

    printf("--- main()\n");

    return 0;
}
