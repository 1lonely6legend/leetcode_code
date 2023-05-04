//
// Created by ogier on 2023/5/4.
//
#include <iostream>
#include <memory>

// 假设我们有一个类叫做 Dependency，它是 PlanningBase 类的一个依赖项
class Dependency {
 public:
  void doSomething() {
    std::cout << "Dependency is doing something!" << std::endl;
  }
};

// 定义一个依赖注入类，用于创建和管理依赖项
class DependencyInjector {
 public:
  std::shared_ptr<Dependency> createDependency() {
    return std::make_shared<Dependency>();
  }
};

// 定义一个类叫做 PlanningBase，它使用了 DependencyInjector 类来注入依赖项 Dependency
class PlanningBase {
 public:
  //*******************************************************
  //在初始化时就注入依赖的类,这就是依赖注入,依赖的类在外部创建,然后传入
  //*******************************************************
  //构造函数的列表初始化
  PlanningBase(const std::shared_ptr<DependencyInjector>& injector)
      : dependency_(injector->createDependency()) {
  }

  void doSomethingWithDependency() {
    //调用依赖项的方法,实现了对依赖项的操作
    dependency_->doSomething();
  }

 private:
  std::shared_ptr<Dependency> dependency_;
};

int main() {
  // 创建一个依赖注入器
  //注入器,其实相当于创建了一个指向依赖项的指针,构造函数中传入这个注入器,相当于来一针?针管里就是依赖项
  std::shared_ptr<DependencyInjector> injector = std::make_shared<DependencyInjector>();

  // 使用依赖注入器来创建 PlanningBase 类的实例
  PlanningBase planningBase(injector);

  // 调用 PlanningBase 类的函数，触发对依赖项的操作
  planningBase.doSomethingWithDependency();

  return 0;
}
