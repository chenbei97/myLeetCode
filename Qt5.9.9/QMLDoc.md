## Loader

Loader用于动态加载QML组件。
加载器可以加载QML文件（使用source属性）或Component对象（使用sourceComponent属性）。这对于将组件的创建延迟到需要时非常有用：例如，应按需创建组件时，或者出于性能原因不应不必要地创建组件时。
这里有一个Loader，当鼠标区域被点击时，它会加载“Page1.qml”作为组件：

```css
import QtQuick 2.0

  Item {
      width: 200; height: 200

      Loader { id: pageLoader }

      MouseArea {
          anchors.fill: parent
          onClicked: pageLoader.source = "Page1.qml"
      }
  }
```

可以使用项属性访问加载的对象。
如果source或sourceComponent发生更改，则所有先前实例化的项都将被销毁。将source设置为空字符串或将sourceComponent设置为undefined会破坏当前加载的对象，从而释放资源并使Loader为空。

如果源组件不是Item类型，Loader不会应用任何特殊的大小调整规则。用于加载视觉类型时，Loader应用以下大小调整规则：

​	如果没有为Loader指定明确的大小，则加载组件后，Loader将自动调整大小为加载项的大小。
​	如果通过设置宽度、高度或锚定明确指定了装载机的尺寸，则装载的项目将调整为装载机的大小。
在这两种情况下，项目和Loader的大小是相同的。这确保了锚定在装载机上等同于锚定在已装载物品上。

```css
import QtQuick 2.0
/*红色矩形的大小将与根项目的大小相同*/
Item {
    width: 200; height: 200
    Loader {
        // Explicitly set the size of the
        // Loader to the parent item's size
        anchors.fill: parent
        // anchors.centerIn: parent 如果改成这个红色矩形为50x50，以根项目为中心
        sourceComponent: rect
    }

Component {
    id: rect
    Rectangle {
        width: 50
        height: 50
        color: "red"
    }
    }
}
```

### Property

Properties

- active: bool：如果Loader当前处于活动状态，则此属性为true。此属性的默认值为true。
  如果Loader处于inactive，则在Loader处于active之前，更改source或sourceComponent不会导致项目实例化。将该值设置为inactive将导致加载程序加载的任何项被释放，但不会影响source或sourceComponent。
  非活动加载程序的状态始终为Null。

- asynchronous : bool: 组件是否将异步实例化。默认情况下为false。当与源属性一起使用时，加载和编译也将在后台线程中执行。异步加载会在多个帧中创建组件声明的对象，并降低动画中出现故障的可能性。异步加载时，状态将更改为Loader.Loading。一旦创建了整个组件，项目将可用，状态将变为Loader.Ready。
  当异步加载正在进行时，将此属性的值更改为false将强制立即同步完成。这允许开始异步加载，然后如果必须在异步加载完成之前访问Loader内容，则强制完成。

  ```css
    Loader {
        source: "mycomponent.qml"
        asynchronous: true
        visible: status == Loader.Ready //可以加载完毕再显示
    }
  ```

- item: object, 此属性包含当前加载的顶级对象

- progress : real, 保存从网络加载QML数据的进度，从0.0（未加载）到1.0（已完成）。大多数QML文件都很小，因此该值将从0快速更改为1

- source : url qml文档的地址

- sourceComponent : Component, 组件对象的id

- status: enumeration ，Loader.Null、Loader.Loading、Loader.Ready、Loader.Error

### Signal

当状态变为Loader.Ready或初始加载成功时，会发出此信号loaded()。
相应的处理程序是onLoaded。

### Method

object setSource(*source*, object *properties*)

创建具有给定属性的给定源组件的对象实例。properties参数是可选的。一旦加载和实例化完成，就可以通过项属性访问该实例。
如果在调用此函数时活动属性为false，则不会加载给定的源组件，但会缓存源属性和初始属性。当加载程序处于活动状态时，将创建具有初始属性集的源组件实例。
以这种方式设置组件实例的初始属性值将不会触发任何关联的行为。
请注意，如果在调用此函数之后但在将加载程序设置为活动之前更改了source或sourceComponent，则缓存的属性将被清除。

```css
// ExampleComponent.qml
  import QtQuick 2.0
  Rectangle {
      id: rect
      color: "red"
      width: 10
      height: 10

      Behavior on color {
          NumberAnimation {
              target: rect
              property: "width"
              to: (rect.width + 20)
              duration: 0
          }
      }
  }
  
// example.qml
  import QtQuick 2.0
  Item {
      Loader {
          id: squareLoader
          onLoaded: console.log(squareLoader.item.width); // 打印加载的父对象的宽度
          // prints [10], not [30]
      }

      Component.onCompleted: {
          squareLoader.setSource("ExampleComponent.qml",
                               { "color": "blue" }); //设置加载的对象和初始颜色,就会调用onLoad
      }
  }
```

## Component

组件是可重用的、封装的QML类型，具有定义良好的接口。
组件通常由组件文件定义，即.qml文件。组件类型本质上允许在QML文档中内联定义QML组件，而不是作为单独的QML文件。这可能有助于重用QML文件中的小组件，或定义逻辑上属于文件中其他QML组件的组件。
例如，这里有一个由多个Loader对象使用的组件。它包含一个项目，一个矩形：

```css
  import QtQuick 2.0

  Item {
      width: 100; height: 100

      Component {
          id: redSquare

          Rectangle {
              color: "red"
              width: 10
              height: 10
          }
      }

      Loader { sourceComponent: redSquare }
      Loader { sourceComponent: redSquare; x: 20 }
  }
```

请注意，虽然矩形本身会自动渲染和显示，但上述矩形的情况并非如此，因为它是在组件内部定义的。该组件将QML类型封装在中，就好像它们是在一个单独的QML文件中定义的一样，并且在请求之前（在本例中，由两个Loader对象）不会加载。因为Component不是从Item派生的，所以不能将任何内容锚定到它。
定义组件类似于定义QML文档。QML文档有一个定义该组件的行为和属性的顶级项，并且不能定义该顶级项之外的属性或行为。同样，组件定义包含一个顶级项（在上面的示例中为矩形），并且不能定义该项之外的任何数据，id（在上面示例中为redSquare）除外。
构件类型通常用于为视图提供图形构件。例如，ListView:：delegate属性需要一个Component来指定如何显示每个列表项。
组件对象也可以使用Qt.createComponent()动态创建。

### Property

progress : real 加载组件的进度，从0.0（未加载任何内容）到1.0（已完成）
status : enumeration Component.Null、Component.Ready、Component.Loading、Component.Error 
url : url 组件URL，这是用于构造组件的URL

### Signal

completed()

在对象实例化后发出。一旦建立了完整的QML环境，这可以用于在启动时执行脚本代码。
相应的处理程序是onCompleted。它可以在任何对象上声明。运行onCompleted处理程序的顺序未定义。

```css
  Rectangle {
      Component.onCompleted: console.log("Completed Running!")
      Rectangle {
          Component.onCompleted: console.log("Nested Completed Running!")
      }
  }
```

destruction() 

在对象开始销毁时发射。这可以用于撤消响应completed（）信号所做的工作，或应用程序中的其他命令性代码。
相应的处理程序是onDestination。它可以在任何对象上声明。onDestination处理程序的运行顺序未定义。

```css
  Rectangle {
      Component.onDestruction: console.log("Destruction Beginning!")
      Rectangle {
          Component.onDestruction: console.log("Nested Destruction Beginning!")
      }
  }
```



### Method

**object createObject(parent, object properties)**

创建并返回此组件的对象实例，该实例将具有给定的父级和属性。properties参数是可选的。如果对象创建失败，则返回null。该对象将在与创建组件的上下文相同的上下文中创建。当对未在QML中创建的组件进行调用时，此函数将始终返回null。
如果希望在不设置父对象的情况下创建对象，请为父值指定null。请注意，如果要显示返回的对象，则必须提供有效的父值或设置返回对象的父属性，否则该对象将不可见。
如果没有向createObject()提供父对象，则必须保留对返回对象的引用，这样它就不会被垃圾收集器破坏。无论以后是否设置Item::parent，这都是正确的，因为设置Item父项不会更改对象所有权。只有图形化的父对象被更改。
从QtQuick 1.1开始，此方法接受一个可选的属性参数，该参数为创建的对象指定初始属性值的映射。这些值将在对象创建完成之前应用。这比在对象创建后设置属性值更有效，尤其是在定义了大量属性值的情况下，还允许在创建对象之前设置属性绑定（使用Qt.binding）。
properties参数被指定为属性值项的映射。例如，下面的代码创建一个初始x和y值分别为100和100的对象：

```javascript
  var component = Qt.createComponent("Button.qml");
  if (component.status == Component.Ready)
      component.createObject(parent, {x: 100, y: 100});
```

**string errorString()**

返回任何错误的可读说明。该字符串包括每个错误的文件、位置和描述。如果存在多个错误，则用换行符分隔。如果不存在错误，则返回一个空字符串。

**object incubateObject(parent, object properties, enumeration mode)**

为该组件的实例创建孵化器。孵化器允许异步实例化新的组件实例，并且不会导致UI冻结。
parent参数指定创建的实例将具有的父级。省略参数或传递null将创建一个没有父对象的对象。在这种情况下，必须保留对创建的对象的引用，这样它就不会被垃圾收集器破坏。properties参数被指定为属性值项的映射，这些属性值项将在创建对象的过程中设置。模式可以是Qt.Synchronous或Qt.Asynchronous，并控制实例是同步创建还是异步创建。默认为异步。在某些情况下，即使指定了Qt.Synchronous，孵化器也可能异步创建对象。如果调用incubateObject()的组件本身是异步创建的，就会发生这种情况。这三个参数都是可选的。

如果成功，该方法将返回一个incubator，否则为null。培养箱具有以下属性：

① incubator的status。有效值为Component.Ready、Component.Loading和Component.Error
② object已创建的对象实例。只有当incubator处于Component.Ready时才可用。
③ onStatusChanged指定状态更改时要调用的回调函数。status作为参数传递给回调。
④ forceCompletion()调用以同步完成孵化。
以下示例演示了如何使用培养箱：

```javascript
var component = Qt.createComponent("Button.qml");

var incubator = component.incubateObject(parent, { x: 10, y: 10 });
if (incubator.status != Component.Ready) {
    incubator.onStatusChanged = function(status) 
    {
        if (status == Component.Ready) {
            print ("Object", incubator.object, "is now ready!");
        }
    }
} else {
    print ("Object", incubator.object, "is ready immediately!");
}
```

