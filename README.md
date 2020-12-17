
## Rezban Andrei

Git Repository for IEP projects.

**N=[3,4,5,6,7]**

Things to do in `lucrareaN` directories (`cd lucrareaN`):

 1. create a **build** folder (`mkdir build`) and access it (`cd build`)
 2. run `cmake ..`
 3. run `make`
 4. run `./executable/main` and the methods called in `main` method from `main.cpp` are executed

 **For lucrarea7, the items 21,22 and 24 are implemented**

 **lucrarea8**

 Things to do in `lucrarea8` directory:

  1. run `make`
  2. run `insmod operations.ko numbers=A,B`( A and B can take integer values ) to insert the kernel module
  3. run `rmmod operations.ko` to remove the kernel module
  4. run `dmesg` to see the module's output (Starts with `Start operations!` and ends with `Finish operations!`)


**lucrarea9**

Things to do in `lucrarea9` directory:

1. take an existing device tree blob and convert it back to a source: `dtc -I dtb -O dts -o new_source_tree.dts existing_devtree.dtb`
2. in `new_source_tree.dts` insert a new node (instead of `8` and `4`, other values can be added):

```
    driver_for_testing
    {
	    compatible = "test,firstdevice";
	    first_number = <8>;
	    second_number = <4>;  
	  };
```

3. create the new device tree blob: `dtc -I dts -O dtb -o existing_devtree.dtb new_source_tree.dts`
4. run `make`
5. run `insmod operations_devicetree.ko` to insert the kernel module
6. run `rmmod operations_devicetree.ko` to remove the kernel module
7. run `dmesg` to see the module's output (Starts with `Start operations from platform device *****!` and ends with `Finish operations!`)

**Devicetree homework isn't properly tested.**

**lucrarea10**

Things to do in `lucrarea10` directory:

 1. create a **build** folder (`mkdir build`) and access it (`cd build`)
 2. run `cmake ..`
 3. run `make`
 4. run `./pasari` and the methods called in `main` method from `pasari.cpp` are executed

 **lucrarea11**

 Things to do in `lucrarea11` directory:

  1. create a **build** folder (`mkdir build`) and access it (`cd build`)
  2. run `cmake ..`
  3. run `make`
  4. run `./figuri` and the methods called in `main` method from `figuri.cpp` are executed
