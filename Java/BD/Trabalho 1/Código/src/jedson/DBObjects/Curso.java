package jedson.DBObjects;

public class Curso {
    int ID;
    String Nome;
    String Sigla;

    @Override
    public String toString() {
        return String.format("(%s)%s", this.Sigla, this.Nome);
    }
}
