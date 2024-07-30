# About MCPPRT
Mcpprt is a minimalistic C++ runtime, useful for lowend machines programming or if you work in bare metal environment

# Description
This little RT implements integer exceptions (instead of expensive RTTI-based C++ exceptions) and wrappers for new/delete.
You can easily modily it, because all code is in file `mrt.cpp`, and it is really little-ass! So far, it uses libc,
but you can write your own `exit()`, `printf()`, `malloc()` and `free()` and not to depend on libc anymore. Or just change
the code of rt :)

# Difference from STL
One big difference - exceptions. they are vary different. first, if you define `try` statement, after it (or one or several
`catch` statements) must be keyword `except` to crash if exception wasn't handled. if you doesn't use `try`, you can skip it.

For example:
```cpp
void crashes(void)
{
    throw 32;
}

int main(void)
{
    crashes();  // will be crash with description of exception (where it was raised)
}

int main(void)
{
    try crashes(); // will ignore an exception
}

int main(void)
{
    try
        crashes();
    catch (64)
        printf("%s", "Exception cought!\n");  // exception will be ignored
}

int main(void)
{
    try
        crashes();
    catch (64)
        ...
    except  // will crash as needs
}

int main(void)
{
    try
        crashes();
    catch (32)
        printf("Oops!\n");  // will print "Oops!"
}
```

# Footer

I hope you will enjoy using my lightweight and portable RT for C++!

If you wanna request an update, but not wanna to implement it, contact me in [Telegram](https://t.me/vi_is_lonely) about that ;)
If you wanna to apply your implemented update, just make a pull request, as usual, updating README also
`Issues` exists if you wanna report a bug :)

Good luck ;>
