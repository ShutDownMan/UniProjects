package models;

import javax.persistence.Column;
import javax.persistence.Id;
import java.io.Serializable;

public class MemoryTagEntityPK implements Serializable {
    private long idMemory;
    private long idTags;

    @Column(name = "id_memory", nullable = false)
    @Id
    public long getIdMemory() {
        return idMemory;
    }

    public void setIdMemory(Long idMemory) {
        this.idMemory = idMemory;
    }

    public void setIdMemory(long idMemory) {
        this.idMemory = idMemory;
    }

    @Column(name = "id_tags", nullable = false)
    @Id
    public long getIdTags() {
        return idTags;
    }

    public void setIdTags(Long idTags) {
        this.idTags = idTags;
    }

    public void setIdTags(long idTags) {
        this.idTags = idTags;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        MemoryTagEntityPK that = (MemoryTagEntityPK) o;

        if (idMemory != that.idMemory) return false;
        if (idTags != that.idTags) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = (int) (idMemory ^ (idMemory >>> 32));
        result = 31 * result + (int) (idTags ^ (idTags >>> 32));
        return result;
    }
}
