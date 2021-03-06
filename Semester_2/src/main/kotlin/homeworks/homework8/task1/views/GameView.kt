package homeworks.homework8.task1.views

import homeworks.homework8.task1.controllers.GameController
import homeworks.homework8.task1.stylesheets.GameFieldStylesheet
import tornadofx.View
import tornadofx.vbox
import tornadofx.addClass
import tornadofx.button
import tornadofx.action
import tornadofx.label

class GameView : View("Game") {
    private val controller: GameController by inject()

    override val root = vbox {
        addClass(GameFieldStylesheet.mainBox)
        label(controller.gameStatusProperty) { addClass(GameFieldStylesheet.statusTitle) }
        this += (GameFieldView::class)
        button("Back to menu") {
            addClass(GameFieldStylesheet.backButton)
            action {
                replaceWith<MainMenu>()
            }
        }
    }

    override fun onDock() {
        controller.setInitialState()
    }
}
