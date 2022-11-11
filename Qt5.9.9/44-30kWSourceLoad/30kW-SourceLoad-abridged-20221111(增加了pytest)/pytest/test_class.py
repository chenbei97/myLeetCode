class MyClass1:
    def __init__(self) -> None:
        pass
    
    def print_info(self,name="cb",sex="m",age=18) -> None:
        s = 'woman' if sex =='w' else 'man'
        print(f"\nthis person's name is {name}, sex is {s}, age is {age}")
        
class MyClass2:
    def __init__(self,name:str,sex:str,age:int) -> None:
       self.name = name
       self.age = age
       self.sex = sex
       print(f"__init__ is called, {self.name} {self.age} {self.sex}")

    def print_info(self) -> None:
        s = 'woman' if self.sex =='w' else 'man'
        print(f"this person's name is {self.name}, sex is {s}, age is {self.age}")

global_m = MyClass2('zhangwei','w',21)

if __name__ == "__main__":
    m1 = MyClass1()
    m1.print_info('chenbei','m',24)
    m2 = MyClass2('cb','w',21)
    m2.print_info()
    
