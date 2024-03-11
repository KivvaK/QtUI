# Шпаргалка по виджетам и другим классам Qt
## QMessageBox (Всплывающее окно с сообщением)
```cpp
#include <QMessageBox>
// ...
QMessageBox msgb;
msgb.setText(text);
msgb.exec();
```

## QString (в примерах leInput – виджет типа QLineEdit с objectName = leInput)
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
## QListWidget (в примерах lwList – виджет типа QListWidget с objectName = lwList)
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
## QTableWidget (в примерах twTable – виджет типа QTableWidget с objectName = twTable)
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
Например, можно создать экземпляр QComboBox(см. ниже) и вставить его в ячейку таблицы:
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
Например, получить текст выбранного варианта в QComboBox(см. ниже) в ячейке таблицы (см. пункт 7):
```cpp
#include <QComboBox>
// ...
QComboBox* cb = dynamic_cast<QComboBox*>(ui->twTable->cellWidget(номер строки, номер столбца));
QString variant = cb->currentText();
```
## QComboBox (в примерах cbxVariants – виджет типа QComboBox с objectName = cbxVariants)
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
