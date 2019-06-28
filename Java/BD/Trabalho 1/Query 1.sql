CREATE TABLE IF NOT EXISTS Aluno(
	AlunoID INT AUTO_INCREMENT,
    CPF VARCHAR(11) NOT NULL,
    Nome VARCHAR(255) NOT NULL,
    Fone VARCHAR(14),
    Emai VARCHAR(64),

    PRIMARY KEY (AlunoID)
);

CREATE TABLE IF NOT EXISTS Curso(
	CursoID INT AUTO_INCREMENT,
    NomeCurso VARCHAR(255) NOT NULL,
	SiglaCurso VARCHAR(64),
    
    PRIMARY KEY (CursoID)
);

CREATE TABLE IF NOT EXISTS Disciplina (
    DisciplinaID INT AUTO_INCREMENT,
    NomeDisciplina VARCHAR(255) NOT NULL,
    
    PRIMARY KEY (DisciplinaID)
);

CREATE TABLE IF NOT EXISTS Professor(
	ProfessorID INT AUTO_INCREMENT,
    Nome VARCHAR(255) NOT NULL,
    Email VARCHAR(64) NOT NULL,

    PRIMARY KEY (ProfessorID)
);

CREATE TABLE IF NOT EXISTS DisciplinaProfessor(
	DisciplinaProfessorID INT AUTO_INCREMENT,
    DisciplinaID INT NOT NULL,
    ProfessorID INT NOT NULL,
    DataInicio VARCHAR(8) NOT NULL,    
    
    PRIMARY KEY (DisciplinaProfessorID),
    FOREIGN KEY (ProfessorID) REFERENCES Professor(ProfessorID),
    FOREIGN KEY (DisciplinaID) REFERENCES Disciplina(DisciplinaID)
);

CREATE TABLE IF NOT EXISTS MatriculaAlunoCurso(
	MatriculaAlunoCursoID INT AUTO_INCREMENT,
    CursoID INT NOT NULL,
    AlunoID INT NOT NULL,
	DataMatricula VARCHAR(8) NOT NULL,
	StatusCurso VARCHAR(255) NOT NULL,

    PRIMARY KEY (MatriculaAlunoCursoID),
    FOREIGN KEY (CursoID) REFERENCES Curso(CursoID),
    FOREIGN KEY (AlunoID) REFERENCES Aluno(AlunoID)
);

CREATE TABLE IF NOT EXISTS MatriculaAlunoAnoLetivo(
	AnoLetivoID INT AUTO_INCREMENT,
    MatriculaAno VARCHAR(4) NOT NULL,
    MatriculaAlunoCursoID INT NOT NULL,
    AnoLetivo TINYINT NOT NULL,
    DataMatricula VARCHAR(8) NOT NULL,
    
    PRIMARY KEY (AnoLetivoID),
    FOREIGN KEY (MatriculaAlunoCursoID) REFERENCES MatriculaAlunoCurso(MatriculaAlunoCursoID)
);

CREATE TABLE IF NOT EXISTS MatriculaAlunoDisciplina(
	MatriculaAlunoDisciplinaID INT AUTO_INCREMENT,
    DisciplinaID INT NOT NULL,
    
    PRIMARY KEY (MatriculaAlunoDisciplinaID),
    FOREIGN KEY (DisciplinaID) REFERENCES Disciplina(DisciplinaID)
);