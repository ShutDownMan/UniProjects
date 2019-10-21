package models;

import javax.persistence.*;

@Entity
@Table(name = "memory_tag", schema = "public", catalog = "memorytaggerdb")
@IdClass(MemoryTagEntityPK.class)
public class MemoryTagEntity {
    private Long idMemory;
    private Long idTags;
    private MemoryEntity memoryByIdMemory;
    private TagsEntity tagsByIdTags;

    @Id
    @Column(name = "id_memory", nullable = false)
    public Long getIdMemory() {
        return idMemory;
    }

    public void setIdMemory(Long idMemory) {
        this.idMemory = idMemory;
    }

    @Id
    @Column(name = "id_tags", nullable = false)
    public Long getIdTags() {
        return idTags;
    }

    public void setIdTags(Long idTags) {
        this.idTags = idTags;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        MemoryTagEntity that = (MemoryTagEntity) o;

        if (idMemory != null ? !idMemory.equals(that.idMemory) : that.idMemory != null) return false;
        if (idTags != null ? !idTags.equals(that.idTags) : that.idTags != null) return false;

        return true;
    }

    @Override
    public int hashCode() {
        int result = idMemory != null ? idMemory.hashCode() : 0;
        result = 31 * result + (idTags != null ? idTags.hashCode() : 0);
        return result;
    }

    @ManyToOne
    @JoinColumn(name = "id_memory", referencedColumnName = "id", nullable = false)
    public MemoryEntity getMemoryByIdMemory() {
        return memoryByIdMemory;
    }

    public void setMemoryByIdMemory(MemoryEntity memoryByIdMemory) {
        this.memoryByIdMemory = memoryByIdMemory;
    }

    @ManyToOne
    @JoinColumn(name = "id_tags", referencedColumnName = "id", nullable = false)
    public TagsEntity getTagsByIdTags() {
        return tagsByIdTags;
    }

    public void setTagsByIdTags(TagsEntity tagsByIdTags) {
        this.tagsByIdTags = tagsByIdTags;
    }
}
