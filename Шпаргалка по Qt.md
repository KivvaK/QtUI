# Шпаргалка по виджетам и другим классам Qt
## QMessageBox (Всплывающее окно с сообщением)
```cpp
#include <QMessageBox>
// ...
QMessageBox msgb;
msgb.setText(text);
msgb.exec();
```

## QString
**(В примерах leInput – виджет типа QLineEdit с objectName = leInput)**  

1.	Преобразование из строки в число:
```cpp
QString s = ui->leInput->text();
bool ok;
double x = s.toDouble(&ok); // int x = s.toInt(&ok);
if (ok) {…}
```
2.	Преобразование из числа в строку:
```cpp
double x = 123.45;
QString s = QString::number(x, 'f', 2); // в скобках - число, формат ('g', 'G', 'f', 'F', 'e', 'E')
					// и число знаков после запятой
					// два последних параметра – не обязательны
```
3.	Преобразование из QString в const char* и обратно:
```cpp
QString s = ui->leInput->text();
const char* c_str = s.toLocal8Bit().data();
…
QString s1 = QString::fromLocal8Bit(c_str);
```
4.	Разделение строки по разделителю:
```cpp
QStringList parts = ui->leInput->text().split(" "); // здесь разделитель - пробел
for (int i = 0; i < parts.length();  i++) {
	// что-то делаем с parts[i], которые являются QString
}
```
## QListWidget
**(В примерах lwList – виджет типа QListWidget с objectName = lwList)**  

1.	Очистка:
```cpp
ui->lwList->clear();
```
2.	Добавить элемент в конец:
```cpp
ui->lwList->addItem(строка типа QString);
```
3.	Проверить, есть ли выделенный элемент:
```cpp
if (ui->lwList->selectionModel()->hasSelection())
```
4.	Номер строки, которую пользователь выделил последней:
```cpp
int index = ui->lwList->selectionModel()->currentIndex().row();
// или
int index = ui->lwFIO->currentIndex().row();
// или
int index = ui->lwList->currentRow();
```
**Примечание.** Если никакой элемент не был выбран, вернётся значение -1.  

5.	Установить/снять выделение строки:
```cpp
ui->lwList->item(индекс строки)->setSelected(true/false);
```
6.	Получить текст строки по индексу:
```cpp
QString s = ui->lwList->item(индекс)->text();
```
7.	Задать текст выделенной строки:
```cpp
ui->lwList->item(индекс)->setText(строка);
```
## QTableWidget
**(В примерах twTable – виджет типа QTableWidget с objectName = twTable)**  

1. Получить количество строк и столбцов:
```cpp
int rowCount = ui->twTable->rowCount();
int colCount = ui->twTable->columnCount();
```
2. Задать количество строк и столбцов:
```cpp
ui->twTable->setRowCount(целое число);
ui->twTable->setColumnCount(целое число);
```
3. Получить объект-содержимое ячейки на пересечении i-й строки и j-го столбца:
```cpp
QTableWidgetItem* item = ui->twTable->item(i, j);
```
*Обратите внимание, что таким образом получается указатель на объект класса QTableWidgetItem*.  
*Получить/задать его текст можно, как обычно:*
```cpp
// подразумевается, что переменная item инициализирована, как в коде выше
QString* value = item->text();	// получить текст
item->setText(строка);		// задать текст
```
**Внимание! Изначально в ячейках нет содержимого! Если пользователь туда ничего не внёс, то метод item() вернёт nullptr.**  
Но можно программно занести в ячейку объект класса QTableWidgetItem, чтобы она не была пустой:
```cpp
// создаём в ячейке новый объект item, только если его нет
if (!ui->twTable->item(i, j))
	ui->twTable->setItem(i, j, new QTableWidgetItem);
```
4. Задать режим изменения размера ячейки по ширине:
```cpp
ui->twTable->horizontalHeader()->setSectionResizeMode(режим);
```
Режим может быть: [QHeaderView::Interactive, QHeaderView::Fixed, QHeaderView::Stretch или QHeaderView::ResizeToContents](https://doc.qt.io/qt-5/qheaderview.html#ResizeMode-enum)  

5. Проверить, был ли выбран элемент таблицы:
```cpp
if (ui->twTable->selectionModel()->hasSelection()) {
	// ...
}
```
6. Получить номер строки последнего выбранного элемента:
```cpp
int row = ui->twTable->selectionModel()->currentIndex().row();
// или
int row = ui->twTable->currentIndex().row();
// или
int row = ui->twTable->currentRow();
```
**Примечание.** Если никакой элемент не был выбран, вернётся значение -1.  

7. Вставить виджет в ячейку таблицы:
```cpp
ui->twTable->setCellWidget(номер строки, номер столбца, виджет);
```
Например, можно создать экземпляр QComboBox (см. ниже) и вставить его в ячейку таблицы:
```cpp
#include <QComboBox>
// ...
QComboBox* cb = new QComboBox();
cb->addItems(QString("Пн,Вт,Ср,Чт,Пт,Сб,Вс").split(","));
iu->twTable->setCellWidget(0, 2, cb);	// Вставит cb в нулевую строку, второй столбец
```
**Примечание.** После подобной вставки владельцем вставленного виджета оказывается twTable, и она управляет жизненным циклом
вставленного виджета, поэтому явно вызывать *delete* для виджета, вставленного в ячейку таблицы, не нужно.  

8. Обратиться к виджету в ячейке таблицы:
```cpp
Тип_виджета* widget = dynamic_cast<тип_виджета*>(ui->twTable->cellWidget(номер строки, номер столбца));
```
Например, получить текст выбранного варианта в QComboBox (см. ниже) в ячейке таблицы (см. пункт 7):
```cpp
#include <QComboBox>
// ...
QComboBox* cb = dynamic_cast<QComboBox*>(ui->twTable->cellWidget(номер строки, номер столбца));
QString variant = cb->currentText();
```
## QComboBox
**(В примерах cbxVariants – виджет типа QComboBox с objectName = cbxVariants)**  

1. Программно вставить элементы:
```cpp
// ui->cbxVariants->insertItems(номер позиции для вставки, список вставляемых элементов в виде QStringList);
// Пример: вставка списка дней недели в начало cbxVariants
ui->cbxVariants->insertItems(0, QString("Пн,Вт,Ср,Чт,Пт,Сб,Вс").split(","));
```
**Примечание.** Можно также заполнить список элементов прямо в редакторе Qt Creator, дважды щёлкнув на cbxVariants.  

2. Очистка:
```cpp
ui->cbxVariants->clear();
```
3. Добавить элементы в конец:
```cpp
// Добавить один элемент в конец
ui->cbxVariants->addItem(строка);
// Добавить несколько элементов в конец
ui->cbxVariants->addItems(список добавляемых элементов в виде QStringList);
```
**Примечание.** Получить QStringList можно, например, из QString при помощи split (см. пункт 1).  

4. Получить номер выбранного элемента:
```cpp
int num = ui->cbxVariants->currentIndex();
```
5. Получить текст выбранного элемента:
```cpp
QString variant = ui->cbxVariants->currentText();
```
6. Программно сделать элемент выбранным:
```cpp
// Сделать выбранным элемент с определённым индексом
ui->cbxVariants->setCurrentIndex(индекс выбираемого элемента);
// Сделать выбранным элемент с определённым текстом
ui->cbxVariants->setCurrentText(текст выбираемого элемента);
```
7. Получить текст элемента по его индексу:
```cpp
QString variant = ui->cbxVariants->itemText(индекс);
```
8. Задать текст элемента по его индексу:
```cpp
ui->cbxVariants->setItemText(индекс, строка);
```
## Главное меню программы
1. Создание главного меню и добавление его пунктов:  
Чтобы создать главное меню программы, в дизайнере Qt Creator, в верхней части создаваемого окна найдите надпись
"Пишите здесь", поставьте туда курсор и введите название пункта меню (например, "Файл", "Правка", "Вид", и т.д.).
Аналогично можно заполнить пункты выпадающего меню.  

2. Создание слота для сигнала нажатия на пункт меню:  
В нижней части дизайнера найдите вкладку "Редактор действий". Если вкладки внизу нет, нажмите правой кнопкой мыши
на светло-серую полосу внизу экрана или на окно свойств виджетов справа снизу и отметьте "Редактор действий". В "Редакторе
действий" нажмите правой кнопкой мыши на соответствующее действие, нажмите "Перейти к слоту..." и выберите triggered().
## Файловый диалог
1. Предоставление пользователю интерфейса выбора имени файла для чтения:
```cpp
#include <QFileDialog>
// ...
QString fileName = QFileDialog::getOpenFileName();
```
2. Предоставление пользователю интерфейса выбора имени файла для записи: 
```cpp
#include <QFileDialog>
// ...
QString fileName = QFileDialog::getSaveFileName();
```
## Диалоговое окно
**(В примерах добавляемый в проект класс диалогового окна называется Dialog)**  
1. Добавление в проект собственного диалогового окна:  
Нажмите правой кнопкой мыши на проект (в левой боковой панели, где отображаются файлы проекта) и выберите:  
*Add new... -> Qt -> Класс формы Qt Designer (ui/h)*  
И далее, при выборе шаблона создаваемого диалога, выберите один из вариантов *"Dialog With Buttons..."*. В результате, если 
не меняли название класса диалогового окна по-умолчанию (Dialog), в проект должны добавиться файлы dialog.ui, dialog.cpp 
и dialog.h - такие же, как для основного окна программы.  

**Примечание.** Если при создании проекта была выбрана система сборки CMake, то в некоторых случаях при добавлении диалогового 
окна Qt Creator может сообщить, что не указал эти файлы в CMakeLists.txt, и предложить сделать это самостоятельно. Тогда нужно открыть
файл CMakeLists.txt и дописать названия добавленных файлов диалогового окна dialog.h, dialog.cpp и dialog.ui в переменную PROJECT_SOURCES.  

2. В заголовочном файле основного окна программы необходимо подключить заголовочный файл диалогового окна:
```cpp
#include "dialog.h"
```
объявить в классе основного окна переменную-**указатель** на диалоговое окно:
```cpp
Dialog* dlg;
```
и в конструкторе основного окна создать экземпляр класса Dialog, выделив память под него при помощи new:
```cpp
dlg = new Dialog(this);
```
Далее обращение к диалоговому окну из кода основного окна программы будет выполняться через переменную dlg.  

3. Показ диалогового окна в немодальном режиме:
```cpp
dlg->show();
```
В этом режиме можно параллельно работать с двумя окнами - основным и диалоговым, переключаясь между ними.  

4. Показ диалогового окна в модальном режиме.  
В этом режиме основное окно программы блокируется до тех пор, пока не будет закрыто диалоговое окно. Кроме того, функция exec() 
возвращает результат - как именно пользователь закрыл диалоговое окно: подтвердив или отклонив действие. 
Проверка, закрыл ли пользователь диалог подтверждением, а не отменой:
```cpp
if (dlg->exec() == QDialog::DialogCode::Accepted) {
	// Код, который должен выполниться при подтверждении пользователем действия в диалоге
}
```
Здесь *dlg->exec()* покажет диалоговое окно, и программа не выйдет из функции *exec* и не продолжит выполнение, пока пользователь 
не закроет диалоговое окно. Когда это произойдёт, функция exec вернёт в качестве результата либо QDialog::DialogCode::Accepted, если 
диалоговое окно закрылось подтверждением от пользователя, либо QDialog::DialogCode::Rejected - в случае отмены.  

5. Настройка кнопок диалогового окна на подтверждение/отмену.  
Если при добавлении в проект диалогового окна в качестве шаблона был выбран один из вариантов *"Dialog With Buttons..."* (см. п. 1), 
то в добавленном окне по-умолчанию будет находиться виджет класса QDialogButtonBox, который изначально содержит две кнопки - подтверждения 
и отмены. При нажатии на любую из них окно, показанное в модальном режиме, закроется, а функция *exec()* (см. п. 4) вернёт 
соответствующий результат.  

Если необходимо самостоятельно реализовать закрытие диалогового окна и возвращение результата при определённых сигналах от определённых виджетов 
(например, от других кнопок), можно в конструкторе диалогового окна явным образом привязать соответствуюие сигналы к **уже существующим** 
слотам accept и reject. Например, если добавли в диалоговое окно собственные кнопки pbYes и pbNo, в конструкторе диалогового окна можно 
написать:
```cpp
connect(
	ui->pbYes, &QAbstractButton::clicked,
	this, &QDialog::accept
);
connect(
	ui->pbNo, &QAbstractButton::clicked,
	this, &QDialog::reject
);
```
Обратите внимание, что *accept* и *reject* - это уже существующие слоты класса QDialog (класса-предка добавленного диалогового окна) -
писать эти слоты самостоятельно в самом классе Dialog - **не нужно**.  

6. Доступ к данным в виджетах диалогового окна из кода основного окна.  
Поскольку все виджеты в окне - private, в коде основного окна невозможно получить доступ к виджетам диалогового окна напрямую. Поэтому для 
чтения и для изменения, например, текста в каком-нибудь QLineEdit диалогового окна, в классе диалогового окна нужно написать соответствующие 
public-функции, и вызывать их в коде основного окна для переменной dlg. Например, написав в диалоговом окне *public* функцию message, 
возвращающую текст, который пользователь ввёл в какой-нибудь QLineEdit диалогового окна, в коде основного окна можно будет получить 
этот текст следующим образом:
```cpp
QString msg = dlg->message();
```
Аналогично с изменением текста в QLineEdit диалогового окна из кода основного окна.

Старайтесь придерживаться правил Qt для названий 
таких функций. Напиример, если функцию чтения сообщения из LineEdit'а диалогового окна назвали message, то функцию записи сообщения 
туда же стоит назвать setMessage.

## Графика
**(В примерах gvDraw - виджет класса QGraphicsView с objectName = gvDraw)**
### Общий порядок действий для формирования изображения
1. Создаётся изображение (в задачах - класса **QPixmap**).

2. Для созданного изображения создаётся экземпляр класса **QPainter**.

3. Методами созданного экземпляра класса **QPainter** строится изображение (рисуются линии, прямоугольники и т.д.).

3.1. Внешний вид рисуемых линий задаётся так называемыми "перьями" (**QPen**), внешний вид сплошных областей - "кистями" (**QBrush**).
Перо/кисть устанавливаются экземпляру **QPainter** методами:
```cpp
p.setPen(перо);
p.setBrush(кисть);
```
Здесь *p* - экземпляр класса **QPainter**. Пример создания и настройки пера - в примерах ниже.

3.2. Названия большинства методов рисования начинаются либо с *draw*, либо с *fill*, после чего идёт название рисуемого примитива
с большой буквы. Методы, начинающиеся с *draw*, рисуют линии и контуры; методы, начинающиеся с *fill* - закрашенные области.
Например (пусть *p* - экземпляр класса **QPainter**):
```cpp
p.drawLine(100, 150, 200, 250);
```
нарисует отрезок прямой из точки с координатами *(100, 150)* в точку с координатами *(200, 250)*. Все координаты - в пикселях.
```cpp
p.fillRect(100, 150, 200, 250, QColor::fromRGB(255, 0, 0));
```
нарисует закрашенную красным цветом прямоугольную область так, что её левый верхний угол будет иметь координаты *(100, 150)*,
ширина прямоугольника будет *200* пикселей, а высота - *250*.

4. Экземпляр класса **QPainter**, разрушаясь, сохраняет изменения в изображение, для которого был создан.

5. Заполненное изображение выводится на экран при помощи одного из виджетов. Ниже рассматривается способ вывода изображения при помощи **QGraphicsView**.

### Подготовка
1. В файле *mainwindow.h* подключите две библиотеки:
```cpp
#include <QGraphicsPixmapItem>
#include <QPen>
```

2. В том же файле, в классе **MainWindow** объявите переменные:
```cpp
// Переменная для хранения изображения
QPixmap image;
// Указатель на отображаемый объект, который будет хранить image
QGraphicsPixmapItem *pmi;
// Цвет фона
QColor bgColor;
// Перо для рисования
QPen pn;
```

3. В файле *mainwindow.cpp*, в конструкторе окна необходимо создать сцену, создать в ней оторбражаемый объект
класса **QGraphicsPixmapItem** и установить созданную сцену сценой для *gvDrawer*:
```cpp
// Создаём сцену, которая будет содержать отображаемые объекты
QGraphicsScene* scene = new QGraphicsScene(this);
// Добавляем изображение в сцену. При этом создаётся отображаемый
// объект класса QGraphicsPixmapItem - сохраняем его адрес в pmi
pmi = scene->addPixmap(image);
// Устанавливаем созданную сцену в качестве сцены gvDrawer
ui->gvDrawer->setScene(scene);
```

Там же инициализируем "инструменты" рисования:
```cpp
// Задаём цвет фона - серый
bgColor = QColor::fromRgb(150, 150, 150);
// Создаём перо жёлтого цвета
pn = QPen(QColor::fromRgb(255, 255, 0));
// Устанавливаем толщину пера 3 пикселя
pn.setWidth(3);
```
### Формирование изображения
4. В файле *mainwindow.cpp* создадим три функции (обратите внимание, что они в примере не являются членами класса **MainWindow** и
"не видят" его переменные - всё необходимое эти функции принимают в качестве параметров):
```cpp
// Функция очистки изображения image цветом color
void clear(QPixmap& image, const QColor color = QColor::fromRgb(0, 255, 255)) {
    // Создаём QPainter для изображения image
    QPainter p(&image);
    // Рисуем закрашенный прямоугольник размером с прямоугольник изображения
    // цветом color
    p.fillRect(image.rect(), color);

    // При выходе из функции p уничтожается, и все изменения сохраняются в image
}

// Функция рисования треугольника на изображении image пером pn
void draw(QPixmap& image, QPen& pn) {
    // Создаём QPainter для изображения image
    QPainter p(&image);
    // Задаём перо для рисования
    p.setPen(pn);

    // Рисуем треугольник
    p.drawLine(100, 100, 200, 100);
    p.drawLine(200, 100, 150, 200);
    p.drawLine(150, 200, 100, 100);

    // При выходе из функции p уничтожается, и все изменения сохраняются в image
}

// Функция вывода текста text в положение (x, y)
// на изображении image пером pn и шрифтом fnt
void print(const QString& text,
           int x, int y,
           QPixmap& image,
           const QPen& pn,
           const QFont& fnt) {
    // Создаём QPainter для изображения image
    QPainter p(&image);
    // Задаём перо и шрифт для вывода текста
    p.setPen(pn);
    p.setFont(fnt);

    // Выводим текст на изображение
    p.drawText(x, y, text);

    // При выходе из функции p уничтожается, и все изменения сохраняются в image
}
```

5. Теперь, когда нужно сформировать изображение (например, в слоте для сигнала *clicked* какой-либо кнопки):
```cpp
// Создаём новое изображение размером с прямоугольник gvDrawer'а,
// сохраняем в image
image = QPixmap(ui->gvDrawer->rect().size());
// Вызываем функцию очистки этого изображения (см. выше) цветом фона
clear(image, bgColor);

// Рисуем треугольник (см. выше) при помощи пера
draw(image, pn);

// Создаём шрифт семейства Helvetica, размер 16, курсивный
QFont fnt("Helvetica", 16);
fnt.setItalic(true);
// Выводим на изображение текст (в нижний угол нарисованного треугольника)
print("Hello, world!", 150, 200, image, pn, fnt);

// Меняем изображение в отображаемом объекте сцены на новое
pmi->setPixmap(image);
```
Обратите внимание на последнюю строчку:
```cpp
pmi->setPixmap(image);
```
Эта команда обновляет изображение в отображаемом объекте сцены. Без неё изменения, которые были выполнены над изображением,
не отразятся на экране.

Теперь, при параметрах инструментов, указанных в п. 3, изображение в gvDrawer закрасится серым цветом, и на нём появится жёлтый треугольник.
