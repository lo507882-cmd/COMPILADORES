package Controllers;

import Logica.logicaClasificador;
import Utilities.Paths;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.stage.Stage;

import java.io.IOException;

public class ClasificadorController {

    @FXML
    private Label lblCurp;

    @FXML
    private TextArea txtEntrada;

    @FXML
    public void initialize() {
        lblCurp.setText("CURP: 0");
    }

    @FXML
    void clasificar(ActionEvent event) {
        String texto = txtEntrada.getText();

        if (texto.trim().isEmpty()) {
            lblCurp.setText("CURP: 0");
            return;
        }

        logicaClasificador analizador = new logicaClasificador();
        analizador.analizar(texto);
        StringBuilder sb = new StringBuilder();
        sb.append("CURP: ").append(analizador.getCurp());

        if (!analizador.getCurps().isEmpty()) {
            sb.append("\n\nCURP encontrada:\n");
            for (String curp : analizador.getCurps()) {
                sb.append("• ").append(curp).append("\n");
            }

            lblCurp.setText(sb.toString());
        }
    }

    @FXML
    void regresar(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource(Paths.MENU));
        Parent root = loader.load();
        Scene scene = new Scene(root);

        Stage stage = (Stage) ((Node) event.getSource()).getScene().getWindow();
        stage.setScene(scene);
        stage.show();
    }
}