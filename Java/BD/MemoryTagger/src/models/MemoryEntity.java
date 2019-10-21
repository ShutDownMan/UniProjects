package models;

import javax.persistence.*;
import java.util.Arrays;
import java.util.Collection;

@Entity
@Table(name = "memory", schema = "public", catalog = "memorytaggerdb")
public class MemoryEntity {
    private Long id;
    private byte[] data;
    private Object date;
    private Long idUser;
    private Long idUservisibility;
    private UserEntity userByIdUser;
    private UservisibilityEntity uservisibilityByIdUservisibility;
    private Collection<MemoryTagEntity> memoryTagsById;

    @Id
    @Column(name = "id", nullable = false)
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    @Basic
    @Column(name = "data", nullable = true)
    public byte[] getData() {
        return data;
    }

    public void setData(byte[] data) {
        this.data = data;
    }

    @Basic
    @Column(name = "date", nullable = true)
    public Object getDate() {
        return date;
    }

    public void setDate(Object date) {
        this.date = date;
    }

    @Basic
    @Column(name = "id_user", nullable = false)
    public Long getIdUser() {
        return idUser;
    }

    public void setIdUser(Long idUser) {
        this.idUser = idUser;
    }

    @Basic
    @Column(name = "id_uservisibility", nullable = false)
    public Long getIdUservisibility() {
        return idUservisibility;
    }

    public void setIdUservisibility(Long idUservisibility) {
        this.idUservisibility = idUservisibility;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        MemoryEntity that = (MemoryEntity) o;

        if (id != null ? !id.equals(that.id) : that.id != null) return false;
        if (!Arrays.equals(data, that.data)) return false;
        if (date != null ? !date.equals(that.date) : that.date != null) return false;
        if (idUser != null ? !idUser.equals(that.idUser) : that.idUser != null) return false;
        if (idUservisibility != null ? !idUservisibility.equals(that.idUservisibility) : that.idUservisibility != null)
            return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = id != null ? id.hashCode() : 0;
        result = 31 * result + Arrays.hashCode(data);
        result = 31 * result + (date != null ? date.hashCode() : 0);
        result = 31 * result + (idUser != null ? idUser.hashCode() : 0);
        result = 31 * result + (idUservisibility != null ? idUservisibility.hashCode() : 0);
        return result;
    }

    @ManyToOne
    @JoinColumn(name = "id_user", referencedColumnName = "id", nullable = false)
    public UserEntity getUserByIdUser() {
        return userByIdUser;
    }

    public void setUserByIdUser(UserEntity userByIdUser) {
        this.userByIdUser = userByIdUser;
    }

    @ManyToOne
    @JoinColumn(name = "id_uservisibility", referencedColumnName = "id", nullable = false)
    public UservisibilityEntity getUservisibilityByIdUservisibility() {
        return uservisibilityByIdUservisibility;
    }

    public void setUservisibilityByIdUservisibility(UservisibilityEntity uservisibilityByIdUservisibility) {
        this.uservisibilityByIdUservisibility = uservisibilityByIdUservisibility;
    }

    @OneToMany(mappedBy = "memoryByIdMemory")
    public Collection<MemoryTagEntity> getMemoryTagsById() {
        return memoryTagsById;
    }

    public void setMemoryTagsById(Collection<MemoryTagEntity> memoryTagsById) {
        this.memoryTagsById = memoryTagsById;
    }
}
