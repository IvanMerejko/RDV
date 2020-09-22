var component;
var sprite;
var x_ = 10;
var y_ = 10;
var id = 1;


function createSpriteObjects(name) {
    component = Qt.createComponent(name);
    if (component.status === Component.Ready)
        finishCreation();
    else
        component.statusChanged.connect(finishCreation);
}

function finishCreation() {
    if (component.status === Component.Ready) {
        sprite = component.createObject(mainWindow, {id: id, x: 100 + x_, y: 100 + y_});
        x_ += 10;
        y_ += 10;
        id ++;
        if (sprite === null) {
            // Error Handling
            console.log("Error creating object");
        }
    } else if (component.status === Component.Error) {
        // Error Handling
        console.log("Error loading component:", component.errorString());
    }
}
