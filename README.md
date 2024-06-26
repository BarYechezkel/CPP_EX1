# System Programming 2 - assignment 1

## Author
- [Bar Yechezkel](https://github.com/BarYechezkel)
- Email: baryechezkel@gmail.com

במטלה זו נמממש מספר אלגוריתמים באמצעות שפת
c++

יש לנו 2 קלאסים:
* Graph 
* Algorithms


## Graph
Graph קלאס זה מייצג את הגרף שיכול להיות מכוון/לא מכוון/ עם משקל/ ללא משקל/ עם צלעות שליליות או חיוביות
אנו מייצגים את הגרף בעזרת מטריצת שכנויות

לכל גרף יש את המאפיינים הבאים:
* isDirected : האם הכרף מכוון או לא
* withWeights : האם הגרף בעל צלעות עם משקל או לא
* hasNegativeEdge : האם בגרף קיימת צלע שלילית
* numOfEdges : מייצד את מספר הצלעות בגרף
  


### Methods

#### loadGraph
פונקציה זו מקבלת מטריצה שתייצג את הגרף, בפוקנציה זו מתבצעות מספר בדיקות כדי לאפיין את הגרף 
 (מכוון / לא מכוון / ממושקל / לא ממושקל / עם צלעות שליליות או לא/ וגם מספר הצלעות בגרף)
אם המטריצה שמקבלים לא תקינה נזרקת שגיאה

#### printGraph
מדפיס את מספר הקודקודים והצלעת של הגרף ואת המטריצה שמייצגת אותו
לדוגמה:

Graph with 3 vertices and 2 edges.
0 1 0 
1 0 1 
0 1 0 




## Algorithms
בקלאס זה נמצאים אלגוריתמים הפועלים על הגרף


### isConnected
* BFS בודק האם הגרף קשיר באמצעות אלגוריתם


### shortestPath
פונקציה למציאת המסלול הקצר ביותר בין נקודת התחלה לנקודת סיום

* BFS אם הגרף ללא משקלים נמצא את המסלול הקצר ביותר באמצעות אלגוריתם 
* dijsktra אם הגרף ממושקל ובעל צלעות חיוביות בלבד נמצא את המסלול הקצר ביותר באמצעות אלגוריתם
* bellmanFord אם הגרף עם משקלים שליליים נמצא את המסלל הקצר ביותר באמצעות אלגוריתם
*  נחזיר "1-" אם אין מסלול קצר ביותר בים הנקודות המבוקשות


### isContainsCycle
הפונקציה בודקת האם קיים מעגל בגרף 
ומחזירה 1 אם קיים או 0 אם לא קיים
 אם קיים מסלול מודפס
 `v1->v2->v3->...->v1`. otherwise, the function will return "-1".


### isBipartite
הפונקציה בודקת האם אפשר לחלק את הגרף ל2 קבוצות קודקודים כך שאין צלעות בין קודקודי כל קבוצה
(בין 2 הקבוצות יכולות להיות צלעות)
אם לא ניתן לחלק מוחזר הערך "0" ואם ניתן מודפס
 * `"The graph is bipartite: A={...}, B={...}"`

 A ,B מייצגות את קבוצת החלוקה לקודקודים

### negativeCycle
הפונקציה בודקת האם קיים מעגל שלילי בגרף ומחזירה
true אם קיים מעגל שלילי
false אם לא קיים מעגל שלילי


## Test
בדיקות למקרי קיצון כדי לבדוק נכונות האלגוריתמים והערכים המוחזרים מהם