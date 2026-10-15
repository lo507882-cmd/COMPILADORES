package Controllers;

import Logica.logicaRFC;
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

public class RFCController {

    @FXML
    private Label lblRFC;

    @FXML
    private TextArea txtEntrada;

    @FXML
    public void initialize() {
        lblRFC.setText("RFC: 0");
    }

    @FXML
    void clasificar(ActionEvent event) {
        String texto = txtEntrada.getText();

        if (texto.trim().isEmpty()) {
            lblRFC.setText("RFC: 0");
            return;
        }

        logicaRFC analizador = new logicaRFC();
        analizador.analizar(texto);
        StringBuilder sb = new StringBuilder();
        sb.append("RFC: ").append(analizador.getRfc());

        if (!analizador.getRfcs().isEmpty()) {
            sb.append("\n\nRFC encontrado:\n");
            for (String rfc : analizador.getRfcs()) {
                sb.append("• ").append(rfc).append("\n");
            }
        }

        lblRFC.setText(sb.toString());
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